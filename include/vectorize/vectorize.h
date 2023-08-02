/** !
 * @file vectorize/vectorize.h 
 * 
 * @author Jacob Smith
 * 
 * Include header for vectorize library
 */

// Include guard
#pragma once

// Standard library
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

// Debug mode
#undef NDEBUG

// Build with AVX2
#define VECTORIZE_BUILD_WITH_AVX2

// Platform dependent macros
#ifdef _WIN64
#define DLLEXPORT extern __declspec(dllexport)
#else
#define DLLEXPORT
#endif

// Memory management macro
#ifndef VECTORIZE_REALLOC
#define VECTORIZE_REALLOC(p, sz) realloc(p,sz)
#endif

// Enumeration definitions
enum operation_type_e
{
    VECTORIZE_OPERATION_ADD = 0,  // 0b0000
    VECTORIZE_OPERATION_SUB = 1,  // 0b0001
    VECTORIZE_OPERATION_MUL = 2,  // 0b0010
    VECTORIZE_OPERATION_DIV = 3,  // 0b0011
    VECTORIZE_OPERATION_RCP = 4,  // 0b0100
    VECTORIZE_OPERATION_SQT = 5,  // 0b0101
    VECTORIZE_OPERATION_STR = 6,  // 0b0110
    VECTORIZE_OPERATION_END = 7,  // 0b0111
    VECTORIZE_OPERATION_RSQ = 8,  // 0b1000
    VECTORIZE_OPERATION_MAX = 9,  // 0b1001
    VECTORIZE_OPERATION_MIN = 10, // 0b1010
    VECTORIZE_OPERATION_AND = 11, // 0b1011
    VECTORIZE_OPERATION_ORR = 12, // 0b1100
    VECTORIZE_OPERATION_XOR = 13, // 0b1101
    VECTORIZE_OPERATION_SHR = 14, // 0b1110
    VECTORIZE_OPERATION_SHL = 15  // 0b1111
};

enum operand_type_e
{
    VECTORIZE_OPERAND_TYPE_CONTEXT = 0,
    VECTORIZE_OPERAND_TYPE_IN      = 1,
    VECTORIZE_OPERAND_TYPE_OUT     = 2,
    VECTORIZE_OPERAND_TYPE_VAR     = 3
};

enum data_stream_format_e
{
    VECTORIZE_FORMAT_8   = 0, // 8-bit int 
    VECTORIZE_FORMAT_16  = 1, // 16-bit int
    VECTORIZE_FORMAT_32  = 2, // 32-bit int
    VECTORIZE_FORMAT_64  = 3, // 64-bit int
    VECTORIZE_FORMAT_F32 = 4, // 32-bit floating point
    VECTORIZE_FORMAT_F64 = 5  // 64-bit floating point
};

// Forward definitions
struct instruction_s;
struct program_s;
struct machine_s;

// Type definitions
typedef unsigned char      u8;
typedef signed char        s8;
typedef unsigned           i8;
typedef unsigned short     u16;
typedef signed short       s16;
typedef short              i16;
typedef unsigned int       u32;
typedef signed int         s32;
typedef int                i32;
typedef unsigned long long u64;
typedef signed long long   s64;
typedef long long          i64;
typedef float              f32;
typedef double             f64;

typedef struct instruction_s instruction;
typedef struct data_stream_s data_stream;
typedef struct machine_s machine;

// Structure definitions

// Instruction
struct instruction_s
{
    enum operation_type_e operation_type;
    struct
    {
        enum operand_type_e operand_type;
        u8 index;
    } operand_1;
    struct
    {
        enum operand_type_e operand_type;
        u8 index;
    } operand_2;
};

// Data stream
struct data_stream_s
{
    bool                       constant;

    void                      *data;
    size_t                     size_in_bytes,
                               size,
                               stride;
    enum data_stream_format_e  format;
};

// Machine 
struct machine_s
{
    
    struct
    {
        size_t  instruction_count,
                program_counter;
        u16    *p_instructions;
    } program;
    
    struct
    {
        size_t (*pfn_add)(void *p_result, void *a, void *b);
        size_t (*pfn_sub)(void *p_result, void *a, void *b);
        size_t (*pfn_mul)(void *p_result, void *a, void *b);
        size_t (*pfn_div)(void *p_result, void *a, void *b);
        size_t (*pfn_rcp)(void *p_result, void *a, void *b);
        size_t (*pfn_sqt)(void *p_result, void *a, void *b);
        size_t (*pfn_str)(void *p_result, void *a, void *b);
        size_t (*pfn_end)(void *p_result, void *a, void *b);
        size_t (*pfn_rsq)(void *p_result, void *a, void *b);
        size_t (*pfn_max)(void *p_result, void *a, void *b);
        size_t (*pfn_min)(void *p_result, void *a, void *b);
        size_t (*pfn_and)(void *p_result, void *a, void *b);
        size_t (*pfn_orr)(void *p_result, void *a, void *b);
        size_t (*pfn_xor)(void *p_result, void *a, void *b);
        size_t (*pfn_shr)(void *p_result, void *a, void *b);
        size_t (*pfn_shl)(void *p_result, void *a, void *b);
    } operation;

    size_t (*operation_functions[16])(void *p_result, void *a, void *b);

    size_t (*conversion_functions[6][6])(void *, void *);

    data_stream *context;
    
    data_stream data[4][8];
    
    size_t buf_len,
           index;

    bool is_running;
};

DLLEXPORT int  instruction_decode ( instruction *p_instruction, u16 instruction_bin );

DLLEXPORT int  instruction_encode ( u16 *p_instruction_bin, instruction _instruction );

DLLEXPORT void instruction_print ( instruction _instruction );

DLLEXPORT int  data_stream_load ( data_stream *p_data_stream, const char *path );

//DLLEXPORT int  data_stream_write ( data_stream *p_data_stream, const char *path );

DLLEXPORT int  data_stream_load_from_file ( data_stream *p_data_stream, enum data_stream_format_e format, const char *path );

DLLEXPORT int  data_stream_read ( data_stream *p_data_stream, enum data_stream_format_e format, size_t items, void *ret );

DLLEXPORT int  machine_load_program ( machine *p_machine, char *path, char *in_0, char *out_0 );

DLLEXPORT int  machine_print_program ( machine _machine );

DLLEXPORT int  machine_add ( machine *p_machine, data_stream *p_a, data_stream *p_b );

DLLEXPORT int  machine_tick ( machine *p_machine );

DLLEXPORT int  machine_run ( machine *p_machine );
