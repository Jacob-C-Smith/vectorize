/*
// Standard library
#include <stdio.h>
#include <stdlib.h>

// vectorize submodule
#include <vectorize/vectorize.h>

// Entry point
int main ( int argc, const char* argv[] )
{

    {
        // Initialized data
        //machine     _machine = { 0 };
        //data_stream _a       = { 0 },
        //            _b       = { 0 };

        // Create data streams
        //(void)data_stream_load_from_file(&_a, VECTORIZE_FORMAT_F32, "examples/A.eddybuffer");
        //(void)data_stream_load_from_file(&_b, VECTORIZE_FORMAT_F32, "examples/B.eddybuffer");

        // Load the add program
        //(void)machine_load_program(&_machine, "examples/add.eddy", "examples/in.eddybuffer", "examples/out.eddybuffer");

        // Start the machine
        //(void)machine_run(&_machine);

    }
    
    

    // Success
    return EXIT_SUCCESS;
}*/

// Standard library
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/mman.h>

typedef unsigned char u8;

enum operation_e
{
    x86_64_OPCODE_ADD = 0b01011000,
    x86_64_OPCODE_SUB = 0b01011100,
    x86_64_OPCODE_MUL = 0b01011001,
    x86_64_OPCODE_DIV = 0b01011110,
    x86_64_OPCODE_MAX = 0b01011111,
    x86_64_OPCODE_MIN = 0b01011101,
};

struct instruction_s;
typedef struct instruction_s instruction;

struct instruction_s
{

    bool vex_3_byte;

    u8 R : 1;
    u8 V : 4;
    u8 L : 1;
    u8 P : 2;

    u8 X : 1;
    u8 B : 1;
    u8 M : 5;
    u8 W : 1;

    u8 DEST : 3;
    u8 IDX1 : 3;
    u8 IDX2 : 3;

    enum operation_e operation;

    instruction *p_next;
};


typedef long(*fn)(long);

fn compile_identity(void)
{
  char *memory = mmap(NULL, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  int i = 0;

  if (memory == MAP_FAILED)
    exit(1);

  // mov %rdi, %rax
  memory[i++] = 0x48;           // REX.W prefix
  memory[i++] = 0x8b;           // MOV opcode, register/register
  memory[i++] = 0xc7;           // MOD/RM byte for %rdi -> %rax

  // ret
  memory[i++] = 0xc3;           // RET opcode

  return (fn) memory;
}

fn vectorize_write_vex_instruction ( instruction vex_instruction )
{

    // Initialized data
    unsigned char *memory   = mmap(NULL, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    size_t  i      = 0;

    // Failed to map the memory
    if ( memory == MAP_FAILED )
      exit(1);

    // Write the VEX
    {

        // Initialized data
        u8 b0 = 0;
        u8 b1 = 0;
        u8 b2 = 0;

        // 3 byte VEX 
        if ( vex_instruction.vex_3_byte )
        {

            // Byte 0
            b0 = 0b11000100;

            // Byte 1
            b1 = vex_instruction.R << 7 | 
                 vex_instruction.X << 6 | 
                 vex_instruction.B << 5 |
                 vex_instruction.M;

            // Byte 2
            b2 = vex_instruction.W << 7 |
                 vex_instruction.V << 3 | 
                 vex_instruction.L << 2 |
                 vex_instruction.P;

            // Write the instruction
            memory[i++] = b0;
            memory[i++] = b1;
            memory[i++] = b2;
        }
        
        // 2 byte VEX
        else
        {

            // Byte 0
            b0 = 0b11000101;

            // Byte 1
            b1 = ( !( vex_instruction.DEST & 0x8 ) ) << 7 | 
                 ( (~(vex_instruction.IDX1)) & 0xF ) << 3 | 
                 vex_instruction.L                   << 2 |
                 vex_instruction.P;

            // Write the instruction
            memory[i++] = b0;
            memory[i++] = b1;
        }
    }

    // Write the OpCode
    {

        // Initialized data
        u8 b0 = vex_instruction.operation;

        // 1 byte OpCode
        // Write the instruction
        memory[i++] = b0;

    }
    
    // Write the MOD R/M
    {

        // Initialized data
        u8 b0 = 0;
        
        b0 |= 0b11000000;
        b0 |= ( vex_instruction.DEST & 0x7 ) << 3;
        b0 |= ( vex_instruction.IDX2 );

        // Write the instruction
        memory[i++] = b0;
    }
    
    // ret
    memory[i++] = 0xc3; // RET opcode
    
    // Write the instruction to a file, and use ndisasm to inspect its contents
    {
        FILE *f = fopen("compiler_out.bin", "w+");

        fwrite(memory, 4, 1, f);

        fclose(f);

        char *AAA = calloc(4096, sizeof(u8));

        sprintf(AAA, "ndisasm -b64 compiler_out.bin");

        system(AAA);
    }
    // Success
    return (fn) memory;
}

int main()
{

    instruction a =
    {
        .vex_3_byte = false,
        .R          = 1,
        .L          = 1,
        .P          = 0,
        .X          = 0,
        .B          = 0,
        .M          = 0,
        .W          = 0,
        .DEST       = 0,
        .IDX1       = 0,
        .IDX2       = 0,
        .operation  = x86_64_OPCODE_MAX,
        .p_next     = 0,
    };

    for (size_t i = 0; i < 7; i++)
        for (size_t j = 0; j < 7; j++)
            for (size_t k = 0; k < 7; k++)
            {

                a.DEST = i;
                a.IDX1 = j;
                a.IDX2 = k;

                fn f = vectorize_write_vex_instruction(a);
                (*f)(0);
                munmap(f, 4096);
            }
    
    // Success
    return EXIT_SUCCESS;
}