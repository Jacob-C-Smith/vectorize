// Standard library
#include <stdio.h>
#include <stdlib.h>

// Include
#include <vectorize/vectorize.h>

// Forward declarations
size_t disassembler_load_file ( const char *path , void *buffer , bool binary_mode );

// Entry point
int main(int argc, const char* argv[])
{

    // Initialized data
    size_t  len         = disassembler_load_file("examples/add.eddy", 0, true);;
    u16    *file_buffer = calloc(len+1, sizeof(u8));


    // Error check
    if ( argc        != 2 ) goto print_usage;
    if ( file_buffer == 0 ) goto print_usage;

    // Load the program
    disassembler_load_file("examples/add.eddy", file_buffer, true);

    // Disassemble the program
    len /= 2;

    // Iterate over each expression
    for (size_t i = 0; i < len; i++)
    {

        // Initialized data
        instruction _instruction = { 0 };

        // Decode the instruction
        instruction_decode(&_instruction, file_buffer[i]);

        // Print the instruction
        instruction_print(_instruction);

        // Newline
        putchar('\n');

    }    

    // Flush stdout
    fflush(stdout);

    // Success
    return EXIT_SUCCESS;

    print_usage:
        printf("Usage: vectorize_disassemble file\n");
        // Success
        return EXIT_SUCCESS;
}

// Load a file
size_t disassembler_load_file ( const char *path , void *buffer , bool binary_mode )
{

    // Argument checking 
    if ( path == (void *) 0 ) goto no_path;

    // Initialized data
    size_t  ret = 0;
    FILE   *f   = fopen(path, (binary_mode) ? "rb" : "r");
    
    // Check if file is valid
    if ( f == NULL )
        goto invalid_file;

    // Find file size and prep for read
    fseek(f, 0, SEEK_END);
    ret = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    // Read to data
    if ( buffer )
        ret = fread(buffer, 1, ret, f);

    // The file is no longer needed
    fclose(f);
    
    // Success
    return ret;

    // Error handling
    {

        // Argument errors
        {
            no_path:
                #ifndef NDEBUG
                    printf("[JSON] Null path provided to function \"%s\n", __FUNCTION__);
                #endif

            // Error
            return 0;
        }

        // File errors
        {
            invalid_file:
                #ifndef NDEBUG
                    printf("[Standard library] Failed to load file \"%s\". %s\n",path, strerror(errno));
                #endif

            // Error
            return 0;
        }
    }
}
