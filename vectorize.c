/** !
 * vectorize library
 * 
 * @file vectorize.c 
 * 
 * @author Jacob Smith
 */

// Headers
#include <vectorize/vectorize.h>

//////////////////////////////////////////////
// Platform dependent function declarations //
//////////////////////////////////////////////

// AVX 512 (512-bits/operation)
#ifdef VECTORIZE_BUILD_WITH_AVX512
    
    ///////////////////////////
    // Cascade SIMD features // 
    ///////////////////////////
    #define VECTORIZE_BUILD_WITH_AVX2

    /////////////
    // AVX 512 //
    /////////////

    // add
    extern size_t machine_add_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_add_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_f64_avx2 ( void *p_result, void *a, void *b );

    // sub

    // mul

    // div

    // max
    extern size_t machine_max_u8_avx512  ( void *p_result, void *a, void *b ); 

    // min
    extern size_t machine_min_u8_avx512  ( void *p_result, void *a, void *b ); 

    // and
    extern size_t machine_and_avx512     ( void *p_result, void *a, void *b );

    // orr
    extern size_t machine_or_avx512      ( void *p_result, void *a, void *b );

    // xor
    extern size_t machine_xor_avx512     ( void *p_result, void *a, void *b );
     
    
    

    // TODO: 
#endif

// AVX 2 (256-bits/operation)
#ifdef VECTORIZE_BUILD_WITH_AVX2

    ///////////////////////////
    // Cascade SIMD features // 
    ///////////////////////////
    #define VECTORIZE_BUILD_WITH_AVX

    ///////////
    // AVX 2 //
    ///////////

    // add 
    extern size_t machine_add_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_add_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_add_f64_avx2 ( void *p_result, void *a, void *b );

    // sub
    extern size_t machine_sub_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_sub_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sub_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sub_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sub_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sub_f64_avx2 ( void *p_result, void *a, void *b );

    // mul
    extern size_t machine_mul_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_mul_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_mul_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_mul_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_mul_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_mul_f64_avx2 ( void *p_result, void *a, void *b );

    // div
    extern size_t machine_div_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_div_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_div_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_div_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_div_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_div_f64_avx2 ( void *p_result, void *a, void *b );

    // rcp
    extern size_t machine_rcp_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_rcp_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_rcp_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_rcp_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_rcp_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_rcp_f64_avx2 ( void *p_result, void *a, void *b );

    // sqt
    extern size_t machine_sqt_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_sqt_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sqt_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sqt_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sqt_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_sqt_f64_avx2 ( void *p_result, void *a, void *b );

    // str
    extern size_t machine_str_u8_avx2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_str_u16_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_str_u32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_str_u64_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_str_f32_avx2 ( void *p_result, void *a, void *b );
    extern size_t machine_str_f64_avx2 ( void *p_result, void *a, void *b );

    // end
    extern size_t machine_end     ( void *p_result, void *a, void *b );

    // rsq

    // max
    extern size_t machine_max_u8_avx2  ( void *p_result, void *a, void *b ); 

    // min
    extern size_t machine_min_u8_avx2  ( void *p_result, void *a, void *b ); 

    // and
    extern size_t machine_and_avx2     ( void *p_result, void *a, void *b );

    // orr
    extern size_t machine_or_avx2      ( void *p_result, void *a, void *b );

    // xor
    extern size_t machine_xor_avx2     ( void *p_result, void *a, void *b );

    // shr

    // shl


    extern size_t machine_sub_u8_avx2 ( void *p_result, void *a, void *b ); 
    extern size_t machine_and_u8_avx2 ( void *p_result, void *a, void *b ); 
    extern size_t machine_orr_u8_avx2 ( void *p_result, void *a, void *b ); 
    extern size_t machine_xor_u8_avx2 ( void *p_result, void *a, void *b ); 
#endif

// AVX 1 (128-bits/operation)
#ifdef VECTORIZE_BUILD_WITH_AVX

    ///////////////////////////
    // Cascade SIMD features // 
    ///////////////////////////
    #define VECTORIZE_BUILD_WITH_SSE42

    /////////
    // AVX //
    /////////

    // add 
    extern size_t machine_add_u8_avx  ( void *p_result, void *a, void *b ); 
    extern size_t machine_add_u16_avx ( void *p_result, void *a, void *b );
    extern size_t machine_add_u32_avx ( void *p_result, void *a, void *b );
    extern size_t machine_add_u64_avx ( void *p_result, void *a, void *b );
    extern size_t machine_add_f32_avx ( void *p_result, void *a, void *b );
    extern size_t machine_add_f64_avx ( void *p_result, void *a, void *b );
    // sub
    extern size_t machine_sub_u8_avx  ( void *p_result, void *a, void *b ); 
    extern size_t machine_sub_u16_avx ( void *p_result, void *a, void *b ); 

    // mul
    // div
    // rcp
    // sqt
    // str
    // end
    // rsq
    // max
    // min
    // and
    extern size_t machine_and_avx ( void *p_result, void *a, void *b );

    // orr
    extern size_t machine_or_avx ( void *p_result, void *a, void *b );

    // xor
    extern size_t machine_xor_avx ( void *p_result, void *a, void *b );

    // shr
    // shl
#endif

// SSE 4.2 (128-bits/operation)
#ifdef VECTORIZE_BUILD_WITH_SSE42

    ///////////////////////////
    // Cascade SIMD features // 
    ///////////////////////////
    #define VECTORIZE_BUILD_WITH_SSE2

    /////////////
    // SSE 4.2 //
    /////////////
#endif

// SSE 2 (128-bits/operation)
#ifdef VECTORIZE_BUILD_WITH_SSE2

    ///////////////////////////
    // Cascade SIMD features // 
    ///////////////////////////
    #define VECTORIZE_BUILD_WITH_INTEGRAL

    ///////////
    // SSE 2 //
    ///////////
    
    // add
    extern size_t machine_add_u8_sse2  ( void *p_result, void *a, void *b ); 
    extern size_t machine_add_u16_sse2 ( void *p_result, void *a, void *b ); 

    // sub
    extern size_t machine_sub_u8_sse2 ( void *p_result, void *a, void *b ); 
    extern size_t machine_sub_u16_sse2 ( void *p_result, void *a, void *b ); 

    // mul
    // div
    // rcp
    // sqt
    // str
    // end
    // rsq
    // max
    // min
    // and
    // orr
    // xor
    // shr
    // shl
#endif

// Integral sizes (64-bits/operation)
#ifdef VECTORIZE_BUILD_WITH_INTEGRAL

    //////////////
    // Integral //
    //////////////

    ////////////////
    // Operations //
    ////////////////

    // add
    size_t machine_add_u8_  ( void *p_result, void *a, void *b ); 
    size_t machine_add_u16_ ( void *p_result, void *a, void *b );
    size_t machine_add_u32_ ( void *p_result, void *a, void *b );
    size_t machine_add_u64_ ( void *p_result, void *a, void *b );
    size_t machine_add_f32_ ( void *p_result, void *a, void *b );
    size_t machine_add_f64_ ( void *p_result, void *a, void *b );

    // sub
    size_t machine_sub_u8_  ( void *p_result, void *a, void *b ); 
    size_t machine_sub_u16_ ( void *p_result, void *a, void *b );
    size_t machine_sub_u32_ ( void *p_result, void *a, void *b );
    size_t machine_sub_u64_ ( void *p_result, void *a, void *b );
    size_t machine_sub_f32_ ( void *p_result, void *a, void *b );
    size_t machine_sub_f64_ ( void *p_result, void *a, void *b );

    // mul
    size_t machine_mul_u8_  ( void *p_result, void *a, void *b ); 
    size_t machine_mul_u16_ ( void *p_result, void *a, void *b );
    size_t machine_mul_u32_ ( void *p_result, void *a, void *b );
    size_t machine_mul_u64_ ( void *p_result, void *a, void *b );
    size_t machine_mul_f32_ ( void *p_result, void *a, void *b );
    size_t machine_mul_f64_ ( void *p_result, void *a, void *b );

    // div
    size_t machine_div_u8_  ( void *p_result, void *a, void *b ); 
    size_t machine_div_u16_ ( void *p_result, void *a, void *b );
    size_t machine_div_u32_ ( void *p_result, void *a, void *b );
    size_t machine_div_u64_ ( void *p_result, void *a, void *b );
    size_t machine_div_f32_ ( void *p_result, void *a, void *b );
    size_t machine_div_f64_ ( void *p_result, void *a, void *b );

    // rcp
    //size_t machine_rcp_u8_  ( void *p_result, void *a, void *b ); 
    //size_t machine_rcp_u16_ ( void *p_result, void *a, void *b );
    //size_t machine_rcp_u32_ ( void *p_result, void *a, void *b );
    //size_t machine_rcp_u64_ ( void *p_result, void *a, void *b );
    //size_t machine_rcp_f32_ ( void *p_result, void *a, void *b );
    //size_t machine_rcp_f64_ ( void *p_result, void *a, void *b );

    // sqt
    //size_t machine_sqt_u8_  ( void *p_result, void *a, void *b ); 
    //size_t machine_sqt_u16_ ( void *p_result, void *a, void *b );
    //size_t machine_sqt_u32_ ( void *p_result, void *a, void *b );
    //size_t machine_sqt_u64_ ( void *p_result, void *a, void *b );
    //size_t machine_sqt_f32_ ( void *p_result, void *a, void *b );
    //size_t machine_sqt_f64_ ( void *p_result, void *a, void *b );

    // str
    //size_t machine_str_u8_  ( void *p_result, void *a, void *b ); 
    //size_t machine_str_u16_ ( void *p_result, void *a, void *b );
    //size_t machine_str_u32_ ( void *p_result, void *a, void *b );
    //size_t machine_str_u64_ ( void *p_result, void *a, void *b );
    //size_t machine_str_f32_ ( void *p_result, void *a, void *b );
    //size_t machine_str_f64_ ( void *p_result, void *a, void *b );

    // end
    size_t machine_end     ( void *p_result, void *a, void *b );

    // rsq

    // max
    size_t machine_max_u8_  ( void *p_result, void *a, void *b );
    size_t machine_max_u16_ ( void *p_result, void *a, void *b );
    size_t machine_max_u32_ ( void *p_result, void *a, void *b );
    size_t machine_max_u64_ ( void *p_result, void *a, void *b );
    size_t machine_max_f32_ ( void *p_result, void *a, void *b );
    size_t machine_max_f64_ ( void *p_result, void *a, void *b );

    // min;
    size_t machine_min_u8_  ( void *p_result, void *a, void *b );
    size_t machine_min_u16_ ( void *p_result, void *a, void *b );
    size_t machine_min_u32_ ( void *p_result, void *a, void *b );
    size_t machine_min_u64_ ( void *p_result, void *a, void *b );
    size_t machine_min_f32_ ( void *p_result, void *a, void *b );
    size_t machine_min_f64_ ( void *p_result, void *a, void *b );
    
    // and
    size_t machine_and_u8_ ( void *p_result, void *a, void *b );
    size_t machine_and_u16_ ( void *p_result, void *a, void *b );
    size_t machine_and_u32_ ( void *p_result, void *a, void *b );
    size_t machine_and_u64_ ( void *p_result, void *a, void *b );
    size_t machine_and_f32_ ( void *p_result, void *a, void *b );
    size_t machine_and_f64_ ( void *p_result, void *a, void *b );

    // orr
    size_t machine_or_u8_  ( void *p_result, void *a, void *b );
    size_t machine_or_u16_ ( void *p_result, void *a, void *b );
    size_t machine_or_u32_ ( void *p_result, void *a, void *b );
    size_t machine_or_u64_ ( void *p_result, void *a, void *b );
    size_t machine_or_f32_ ( void *p_result, void *a, void *b );
    size_t machine_or_f64_ ( void *p_result, void *a, void *b );
    
    // xor
    size_t machine_xor_u8_  ( void *p_result, void *a, void *b );
    size_t machine_xor_u16_ ( void *p_result, void *a, void *b );
    size_t machine_xor_u32_ ( void *p_result, void *a, void *b );
    size_t machine_xor_u64_ ( void *p_result, void *a, void *b );
    size_t machine_xor_f32_ ( void *p_result, void *a, void *b );
    size_t machine_xor_f64_ ( void *p_result, void *a, void *b );

    // shr

    // shl
    
    /////////////////
    // Conversions //
    /////////////////

    // 8-bit -> X
    size_t machine_conv_8_16_    ( void *p_result, void *a );
    size_t machine_conv_8_32_    ( void *p_result, void *a );
    size_t machine_conv_8_64_    ( void *p_result, void *a );
    size_t machine_conv_8_f32_   ( void *p_result, void *a );
    size_t machine_conv_8_f64_   ( void *p_result, void *a );

    // 16-bit -> X
    size_t machine_conv_16_8_    ( void *p_result, void *a );
    size_t machine_conv_16_32_   ( void *p_result, void *a );
    size_t machine_conv_16_64_   ( void *p_result, void *a );
    size_t machine_conv_16_f32_  ( void *p_result, void *a );
    size_t machine_conv_16_f64_  ( void *p_result, void *a );

    // 32-bit -> X
    size_t machine_conv_32_8_    ( void *p_result, void *a );
    size_t machine_conv_32_16_   ( void *p_result, void *a );
    size_t machine_conv_32_64_   ( void *p_result, void *a );
    size_t machine_conv_32_f32_  ( void *p_result, void *a );
    size_t machine_conv_32_f64_  ( void *p_result, void *a );

    // 64-bit -> X
    size_t machine_conv_64_8_    ( void *p_result, void *a );
    size_t machine_conv_64_16_   ( void *p_result, void *a );
    size_t machine_conv_64_32_   ( void *p_result, void *a );
    size_t machine_conv_64_f32_  ( void *p_result, void *a );
    size_t machine_conv_64_f64_  ( void *p_result, void *a );

    // 32-bit -> X
    size_t machine_conv_f32_8_   ( void *p_result, void *a );
    size_t machine_conv_f32_16_  ( void *p_result, void *a );
    size_t machine_conv_f32_32_  ( void *p_result, void *a );
    size_t machine_conv_f32_64_  ( void *p_result, void *a );
    size_t machine_conv_f32_f64_ ( void *p_result, void *a );

    // 64-bit -> X
    size_t machine_conv_f64_8_   ( void *p_result, void *a );
    size_t machine_conv_f64_16_  ( void *p_result, void *a );
    size_t machine_conv_f64_32_  ( void *p_result, void *a );
    size_t machine_conv_f64_64_  ( void *p_result, void *a );
    size_t machine_conv_f64_f32_ ( void *p_result, void *a );

#endif

size_t load_file ( const char *path , void *buffer , bool binary_mode )
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

int instruction_decode ( instruction *p_instruction, u16 instruction_bin )
{
    
    // Argument check
    if ( p_instruction == (void *) 0 ) goto no_instruction;

    // Initialized data    
    enum operation_type_e operation_type  = ( instruction_bin & 0xE000 ) >> 13; // 1110 0000 0000 0000
    enum operand_type_e   operand_1_type  = ( instruction_bin & 0x0C00 ) >> 10; // 0000 1100 0000 0000
    u8                    operand_1_index = ( instruction_bin & 0x01C0 ) >> 6;  // 0000 0001 1100 0000
    enum operand_type_e   operand_2_type  = ( instruction_bin & 0x0038 ) >> 4;  // 0000 0000 0011 1000
    u8                    operand_2_index = ( instruction_bin & 0x0007 );       // 0000 0000 0000 0111

    // Populate the return value
    *p_instruction = (instruction)
    {

        // Operation type. one of < ADD, SUB, MUL, DIV, RCP, SQT, STR, END >
        .operation_type = operation_type,

        // Operand 1. type = context, in, out, var
        .operand_1 =
        {
            .operand_type = operand_1_type,
            .index        = operand_1_index
        },

        // Operand 2. type = context, in, var
        .operand_2 = 
        {
            .operand_type = operand_2_type,
            .index        = operand_2_index
        }
    };

    // Success
    return 1;
    
    // Error handling
    {
    
        // Argument error
        {
            no_instruction:
                #ifndef NDEBUG
                    printf("[vectorize] Null pointer provided for parameter \"p_instruction\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int instruction_encode ( u16 *p_instruction_bin, instruction _instruction )
{

    // Argument check
    if ( p_instruction_bin == (void *) 0 ) goto no_instruction_bin;

    // Initialized data
    u16 instruction_bin = 0;

    // Construct the instruction word
    instruction_bin |= ( _instruction.operation_type         << 13 );
    instruction_bin |= ( _instruction.operand_1.operand_type << 10 );
    instruction_bin |= ( _instruction.operand_1.index        << 6 );
    instruction_bin |= ( _instruction.operand_2.operand_type << 4 );
    instruction_bin |= ( _instruction.operand_2.index );

    // Return the instruction word to the caller
    *p_instruction_bin = instruction_bin;

    // Success
    return 1;

    // Error handling
    {
    
        // Argument error
        {
            no_instruction_bin:
                #ifndef NDEBUG
                    printf("[vectorize] Null pointer provided for parameter \"p_instruction_bin\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

void instruction_print ( instruction  _instruction )
{

    // Switch on the type of the instruction
    switch ( _instruction.operation_type )
    {

        // Print ADD
        case VECTORIZE_OPERATION_ADD:
            printf("ADD");
            break;

        // Print SUB
        case VECTORIZE_OPERATION_SUB:
            printf("SUB");
            break;

        // Print MUL
        case VECTORIZE_OPERATION_MUL:
            printf("MUL");
            break;
        
        // Print DIV
        case VECTORIZE_OPERATION_DIV:
            printf("DIV");
            break;
        
        // Print RCP
        case VECTORIZE_OPERATION_RCP:
            printf("RCP");
            break;

        // Print SQRT
        case VECTORIZE_OPERATION_SQT:
            printf("SQT");
            break;

        // Print STR
        case VECTORIZE_OPERATION_STR:
            printf("STR");
            break;
        
        // Print END
        case VECTORIZE_OPERATION_END:
            printf("END");
            goto end;
        
        // Print RSQ
        case VECTORIZE_OPERATION_RSQ:
            printf("RSQ");

    }

    // Formatting
    putchar(' ');
    
    // Switch on the first operand type
    switch (_instruction.operand_1.operand_type)
    {

        // Print CONTEXT
        case VECTORIZE_OPERAND_TYPE_CONTEXT:
            printf("CONTEX");
            break;

        // Print IN
        case VECTORIZE_OPERAND_TYPE_IN:
            printf("IN[%d]", _instruction.operand_1.index);
            break;
        
        // Print OUT
        case VECTORIZE_OPERAND_TYPE_OUT:
            printf("OUT[%d]", _instruction.operand_1.index);
            break;
        
        // Print VAR
        case VECTORIZE_OPERAND_TYPE_VAR:
            printf("VAR[%d]", _instruction.operand_1.index);
            break;
    }

    // Formatting
    putchar(',');
    putchar(' ');


    // Switch on the second operand type
    switch (_instruction.operand_2.operand_type)
    {

        // Print CONTEXT
        case VECTORIZE_OPERAND_TYPE_CONTEXT:
            printf("CONTEXT");
            break;
        
        // Print IN
        case VECTORIZE_OPERAND_TYPE_IN:
            printf("IN[%d]", _instruction.operand_2.index);
            break;

        // Print OUT
        case VECTORIZE_OPERAND_TYPE_OUT:
            printf("OUT[%d]", _instruction.operand_2.index);
            break;

        // Print VAR
        case VECTORIZE_OPERAND_TYPE_VAR:
            printf("VAR[%d]", _instruction.operand_2.index);
            break;
    }

    end:

    // Success
    return;
}

int data_stream_load ( data_stream *p_data_stream, const char *path )
{

    // Initialized data

    // Success
    return 1;
}

int data_stream_read ( data_stream *p_data_stream, enum data_stream_format_e format, size_t items, void *ret )
{

    //void (*pfn_conv_func)()= 0;

    // Success
    return 1;
}

int machine_load_program ( machine *p_machine, char *path, char *in_0, char *out_0 )
{

    /* 
     * ////////////////
     * // Commentary //
     * ////////////////
     * 
     * Machines run programs. Programs are lists of instructions. Instructions are encoded as words.
     * The encoding is described below
     * 
     * /////////////////
     * // Instruction //
     * /////////////////
     *
     *  This graphic shows the bits of an opcode word
     * 
     * ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────╮
     * │ 16 │ 15 │ 14 │ 13 │ 12 │ 11 │ 10 │ 9  │ 8  │ 7  │ 6  │ 5  │ 4  │ 3  │ 2  │ 1  │ 0  │
     * ╰─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──╯
     *   ├────┴────┴────╯    │    │    │    │    │    │    │    │    │    │    │    │    │
     *   │                   │    │    │    │    │    │    │    │    │    │    │    │    │
     *   │    ╭──────────────┴────╯    │    │    │    │    ╰────┤    │    │    │    │    │
     *   │    │    ╭───────────────────┴────┴────┴────╯         │    │    │    │    │    │
     *   │    │    │                                            │    │    │    │    │    │
     *   │    │    │                                            │    ╰────┴────┴────┴────┴────╮
     *   │    │    │                                            ╰───────────╮                 │
     *   │    │  ╭─┴───────────────╮                                      ╭─┴───────────────╮ │ 
     *   │    │  │ INDEX : 0 - 7   │                                      │ INDEX : 0 - 7   │ │ 
     *   │    │  ├─────────────────┤ ╭────────────────┬─────────────────╮ ├─────────────────┤ │ 
     *   │    │  │ Opcode 1 index  │ │ ADD = 0000 (0) │ RSQ = 1000 (8)  │ │ Opcode 2 index  │ │ 
     *   │    │  ╰─────────────────╯ │ SUB = 0001 (1) │ MAX = 1001 (9)  │ ╰─────────────────╯ │ 
     *   │    │                      │ MUL = 0010 (2) │ MIN = 1010 (10) │                     │ 
     *   │  ╭─┴──────────────────╮   │ DIV = 0011 (3) │ AND = 1011 (11) │  ╭──────────────────┴─╮
     *   │  │ CONTEXT = 0000 (0) │   │ RCP = 0100 (4) │ OR  = 1100 (12) │  │ CONTEXT = 0000 (0) │
     *   │  │ IN      = 0001 (1) │   │ SQR = 0101 (5) │ XOR = 1111 (13) │  │ IN      = 0001 (1) │
     *   │  │ OUT     = 0010 (2) │   │ STR = 0110 (6) │ SHR = 1110 (14) │  │ VAR     = 0011 (3) │
     *   │  │ VAR     = 0011 (3) │   │ END = 0111 (7) │ SHL = 1101 (15) │  ├────────────────────┤
     *   │  ├────────────────────┤   ├────────────────┴─────────────────┤  │   Opcode 2 types   │
     *   │  │   Opcode 1 types   │   │         Operation codes          │  ╰────────────────────╯
     *   │  ╰────────────────────╯   ╰────────────────┼─────────────────╯                        
     *   │                                            │
     *   ╰────────────────────────────────────────────╯
     * 
     * ////////////////
     * // Conversion //
     * ////////////////
     * 
     * These conversions are run on buffer reads / writes
     * 
     * // TODO: Make sure FRM/TO is not TO/FRM
     * 
     * ╭────────┬───────┬───────┬────────┬────────┬────────┬────────╮
     * │ FRM/TO │ BYTE  │ WORD  │ DWORD  │ QWORD  │ SINGLE │ DOUBLE │
     * ├────────┼───────┼───────┼────────┼────────┼────────┼────────┤
     * │ BYTE   │ NULL  │ B->W  │ B->DW  │ B->QW  │ B->SF  │ B->DF  │
     * ├────────┼───────┼───────┼────────┼────────┼────────┼────────┤
     * │ WORD   │ W->B  │ NULL  │ W->DW  │ W->QW  │ W->SF  │ W->DF  │
     * ├────────┼───────┼───────┼────────┼────────┼────────┼────────┤
     * │ DWORD  │ DW->B │ DW->W │ NULL   │ DW->QW │ DW->SF │ DW->DF │
     * ├────────┼───────┼───────┼────────┼────────┼────────┼────────┤
     * │ QWORD  │ QW->B │ QW->W │ QW->DW │ NULL   │ QW->SF │ QW->DF │
     * ├────────┼───────┼───────┼────────┼────────┼────────┼────────┤
     * │ SINGLE │ SF->B │ SF->W │ SF->DW │ SF->QW │ NULL   │ SF->DF │
     * ├────────┼───────┼───────┼────────┼────────┼────────┼────────┤
     * │ DOUBLE │ DF->B │ DF->W │ DF->DW │ DF->QW │ DF->SF │ NULL   │
     * ╰────────┴───────┴───────┴────────┴────────┴────────┴────────╯
     * 
     * ////////////////
     * // Operations //
     * ////////////////
     * 
     * Detailed description of operations
     * 
     * // TODO: Make sure vocabulary accurately represents operations
     * 
     * ╭────────┬────────────────┬────────────────┬─────────────────────────────────────────────╮
     * │ Name   │ Operand 1      │ Operand 2      │ Description                                 │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ ADD    │ summand        │ summand        │ Add Op 1 to Op 2. Store in _                │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ SUB    │ minuend        │ subtrahend     │ Subtract Op 2 from Op 1. Store in _         │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ MUL    │ multiplier     │ multiplicand   │ Multiply Op 1 and Op 2. Store in _          │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ DIV    │ dividend       │ divisor        │ Divide Op 2 by Op 1. Store in _             │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ RCP    │ value          │  [ NOT USED ]  │ Store the inverse of Op 1 in _              │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ SQT    │ value          │  [ NOT USED ]  │ Store the square root of Op 1 in _          │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ STR    │ output         │ input          │ Store Op 2 into Op 1                        │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ END    │  [ NOT USED ]  │  [ NOT USED ]  │ Halt program execution                      │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ RSQ    │ value          │  [ NOT USED ]  │ Store the inverse square root of Op 1 in _  │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ MAX    │ value A        │ value B        │ Store the larger of Op 1 and Op 2 in _      │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ MIN    │ value A        │ value B        │ Store the smaller of Op 1 and Op 2 in _     │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ AND    │ value A        │ value B        │ And the bits of Op 1 and op 2. Store in _   │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ OR     │ value A        │ value B        │ Or the bits of Op 1 and op 2. Store in _    │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ XOR    │ value A        │ value B        │ Xor the bits of Op 1 and op 2. Store in _   │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ SHR    │ value          │  [ NOT USED ]  │ Shift bits of Op 1 to the right. Store in _ │
     * ├────────┼────────────────┼────────────────┼─────────────────────────────────────────────┤
     * │ SHL    │ value          │  [ NOT USED ]  │ Shift bits of Op 1 to the left. Store in _  │
     * ╰────────┴────────────────┴────────────────┴─────────────────────────────────────────────╯
     */

    // Initialzied data
    size_t   len                                      = load_file(path, 0, true),
             _instruction_count                       = len / 2,
           (*p_add_best)     (void *, void *, void *) = 0,
           (*p_sub_best)     (void *, void *, void *) = 0,
           (*p_mul_best)     (void *, void *, void *) = 0,
           (*p_div_best)     (void *, void *, void *) = 0,
           (*p_rcp_best)     (void *, void *, void *) = 0,
           (*p_sqt_best)     (void *, void *, void *) = 0,
           (*p_str_best)     (void *, void *, void *) = 0,
           (*p_end_best)     (void *, void *, void *) = 0,
           (*p_rsq_best)     (void *, void *, void *) = 0,
           (*p_max_best)     (void *, void *, void *) = 0,
           (*p_min_best)     (void *, void *, void *) = 0,
           (*p_and_best)     (void *, void *, void *) = 0,
           (*p_orr_best)     (void *, void *, void *) = 0,
           (*p_xor_best)     (void *, void *, void *) = 0,
           (*p_shr_best)     (void *, void *, void *) = 0,
           (*p_shl_best)     (void *, void *, void *) = 0,
           (*p_i8_i16_best)  (void *, void *)         = 0,
           (*p_i8_i32_best)  (void *, void *)         = 0,
           (*p_i8_i64_best)  (void *, void *)         = 0,
           (*p_i8_f32_best)  (void *, void *)         = 0,
           (*p_i8_f64_best)  (void *, void *)         = 0,
           (*p_i16_i8_best)  (void *, void *)         = 0,
           (*p_i16_i32_best) (void *, void *)         = 0,
           (*p_i16_i64_best) (void *, void *)         = 0,
           (*p_i16_f32_best) (void *, void *)         = 0,
           (*p_i16_f64_best) (void *, void *)         = 0,
           (*p_i32_i8_best)  (void *, void *)         = 0,
           (*p_i32_i16_best) (void *, void *)         = 0,
           (*p_i32_i64_best) (void *, void *)         = 0,
           (*p_i32_f32_best) (void *, void *)         = 0,
           (*p_i32_f64_best) (void *, void *)         = 0,
           (*p_i64_i8_best)  (void *, void *)         = 0,
           (*p_i64_i16_best) (void *, void *)         = 0,
           (*p_i64_i32_best) (void *, void *)         = 0,
           (*p_i64_f32_best) (void *, void *)         = 0,
           (*p_i64_f64_best) (void *, void *)         = 0,
           (*p_f32_i8_best)  (void *, void *)         = 0,
           (*p_f32_i16_best) (void *, void *)         = 0,
           (*p_f32_i32_best) (void *, void *)         = 0,
           (*p_f32_i64_best) (void *, void *)         = 0,
           (*p_f32_f64_best) (void *, void *)         = 0,
           (*p_f64_i8_best)  (void *, void *)         = 0,
           (*p_f64_i16_best) (void *, void *)         = 0,
           (*p_f64_i32_best) (void *, void *)         = 0,
           (*p_f64_i64_best) (void *, void *)         = 0,
           (*p_f64_f32_best) (void *, void *)         = 0;
    u16     *p_instructions                           = VECTORIZE_REALLOC(0, sizeof(char) * (len));
    int      format_stride                            = 1;
    size_t (*conversion_functions[6][6])()            = { 0 };

    // Load the binary from a path
    load_file(path, p_instructions, true);

    // Set the operation callbacks
    switch ( format_stride )
    {

        // Machine is processing bytes
        case 1:

            // Set the best byte operations
            {

                // Platform dependent implementation
                #ifdef VECTORIZE_BUILD_WITH_INTEGRAL

                    ///////////////////////////////////////////
                    // Best byte functions for integral type //
                    ///////////////////////////////////////////
                    p_add_best = machine_add_u8_,
                    p_sub_best = machine_sub_u8_,
                    p_mul_best = machine_mul_u8_,
                    p_div_best = machine_div_u8_,
                    p_rcp_best = 0, // machine_rcp_u8_,
                    p_sqt_best = 0, // machine_sqt_u8_,
                    p_str_best = 0, // machine_str_u8_,
                    p_rsq_best = 0, // machine_rsq_u8_,
                    p_max_best = machine_max_u8_,
                    p_min_best = machine_min_u8_,
                    p_and_best = machine_and_u8_,
                    p_orr_best = machine_or_u8_,
                    p_xor_best = machine_xor_u8_,
                    p_shr_best = 0, // machine_shr_u8_,
                    p_shl_best = 0; // machine_shl_u8_

                    #ifdef VECTORIZE_BUILD_WITH_SSE2

                        ///////////////////////////////////
                        // Best byte functions for SSE 2 //
                        ///////////////////////////////////
                        p_add_best = machine_add_u8_sse2;
                        p_sub_best = machine_sub_u8_sse2;

                        #ifdef VECTORIZE_BUILD_WITH_SSE42

                            /////////////////////////////////////
                            // Best byte functions for SSE 4.2 //
                            /////////////////////////////////////
                            // TODO:

                            #ifdef VECTORIZE_BUILD_WITH_AVX

                                /////////////////////////////////
                                // Best byte functions for AVX //
                                /////////////////////////////////
                                p_add_best = machine_add_u8_avx;
                                p_sub_best = machine_sub_u8_avx;

                                p_and_best = machine_and_avx;
                                p_orr_best = machine_or_avx;
                                p_xor_best = machine_xor_avx;

                                #ifdef VECTORIZE_BUILD_WITH_AVX2

                                    ///////////////////////////////////
                                    // Best byte functions for AVX 2 //
                                    ///////////////////////////////////
                                    p_add_best = machine_add_u8_avx2;
                                    p_sub_best = machine_sub_u8_avx2;


                                    p_max_best = machine_max_u8_avx2;
                                    p_min_best = machine_min_u8_avx2;

                                    p_and_best = machine_and_avx2;
                                    p_orr_best = machine_or_avx2;
                                    p_xor_best = machine_xor_avx2;

                                    #ifdef VECTORIZE_BUILD_WITH_AVX512_FOUNDATION 

                                        /////////////////////////////////////
                                        // Best byte functions for AVX 512 //
                                        /////////////////////////////////////

                                        #ifdef VECTORIZE_BUILD_WITH_AVX512_VECTOR_LENGTH
                                            #ifdef VECTORIZE_BUILD_WITH_AVX512_BYTE_WORD
                                                ///////////////////////////////////////////////
                                                // Best byte functions for AVX 512 + VL + BW //
                                                ///////////////////////////////////////////////
                                                p_add_best = machine_add_u8_avx512;
                                                p_sub_best = machine_sub_u8_avx512;
                                            #endif
                                        #endif
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            }
            break;

        // Machine is processing words
        case 2:

            // Set the best word operations
            {
                            
                // Platform dependent implementation
                #ifdef VECTORIZE_BUILD_WITH_INTEGRAL
            
                    ///////////////////////////////////////////
                    // Best byte functions for integral type //
                    ///////////////////////////////////////////
                    p_add_best = machine_add_u16_,
                    p_sub_best = machine_sub_u16_,
                    p_mul_best = machine_mul_u16_,
                    p_div_best = machine_div_u16_,
                    //p_rcp_best = machine_rcp_u16_,
                    //p_sqt_best = machine_sqt_u16_,
                    //p_str_best = machine_str_u16_,
                    p_rsq_best = 0,
                    p_max_best = machine_max_u16_,
                    p_min_best = machine_min_u16_,
                    p_and_best = machine_and_u16_,
                    p_orr_best = machine_or_u16_,
                    p_xor_best = machine_xor_u16_,
                    p_shr_best = 0,
                    p_shl_best = 0; 
            
                    #ifdef VECTORIZE_BUILD_WITH_SSE2
            
                        ///////////////////////////////////
                        // Best byte functions for SSE 2 //
                        ///////////////////////////////////
                        //p_add_best = machine_add_u16_sse2;
                        //p_sub_best = machine_sub_u16_sse2;
            
                        #ifdef VECTORIZE_BUILD_WITH_SSE42
            
                            /////////////////////////////////////
                            // Best byte functions for SSE 4.2 //
                            /////////////////////////////////////
                            // TODO:
                            
                            #ifdef VECTORIZE_BUILD_WITH_AVX
            
                                /////////////////////////////////
                                // Best byte functions for AVX //
                                /////////////////////////////////
                                //p_add_best = machine_add_u16_avx;
                                //p_sub_best = machine_sub_u16_avx;
            
                                p_and_best = machine_and_avx;
                                p_orr_best = machine_or_avx;
                                p_xor_best = machine_xor_avx;
            
                                #ifdef VECTORIZE_BUILD_WITH_AVX2
            
                                    ///////////////////////////////////
                                    // Best byte functions for AVX 2 //
                                    ///////////////////////////////////
                                    p_add_best = machine_add_u16_avx2;
                                    p_sub_best = machine_sub_u16_avx2;
            
                                    //p_max_best = machine_max_u16_avx2;
                                    //p_min_best = machine_min_u16_avx2;
            
                                    p_and_best = machine_and_avx2;
                                    p_orr_best = machine_or_avx2;
                                    p_xor_best = machine_xor_avx2;
            
                                    #ifdef VECTORIZE_BUILD_WITH_AVX512_FOUNDATION 
            
                                        /////////////////////////////////////
                                        // Best byte functions for AVX 512 //
                                        /////////////////////////////////////
            
                                        #ifdef VECTORIZE_BUILD_WITH_AVX512_VECTOR_LENGTH
                                            #ifdef VECTORIZE_BUILD_WITH_AVX512_BYTE_WORD
                                                ///////////////////////////////////////////////
                                                // Best byte functions for AVX 512 + VL + BW //
                                                ///////////////////////////////////////////////
                                                p_add_best = machine_add_u8_avx512;
                                                p_sub_best = machine_sub_u8_avx512;

                                                p_max_best = machine_max_u16_avx512;
                                                p_min_best = machine_min_u16_avx512;

                                                p_and_best = machine_and_avx512;
                                                p_orr_best = machine_or_avx512;
                                                p_xor_best = machine_xor_avx512;
                                            #endif
                                        #endif
            
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            }
            break;

        // Machine is processing double words
        case 4:

            // Set the best double word operations
            {
                            
                // Platform dependent implementation
                #ifdef VECTORIZE_BUILD_WITH_INTEGRAL
            
                    ///////////////////////////////////////////
                    // Best byte functions for integral type //
                    ///////////////////////////////////////////
                    p_add_best = machine_add_u32_,
                    p_sub_best = machine_sub_u32_,
                    p_mul_best = machine_mul_u32_,
                    p_div_best = machine_div_u32_,
                    //p_rcp_best = machine_rcp_u32_,
                    //p_sqt_best = machine_sqt_u32_,
                    //p_str_best = machine_str_u32_,
                    p_rsq_best = 0,
                    p_max_best = machine_max_u32_,
                    p_min_best = machine_min_u32_,
                    p_and_best = machine_and_u32_,
                    p_orr_best = machine_or_u32_,
                    p_xor_best = machine_xor_u32_,
                    p_shr_best = 0,
                    p_shl_best = 0; 
            
                    #ifdef VECTORIZE_BUILD_WITH_SSE2
            
                        //////////////////////////////////////////
                        // Best double word functions for SSE 2 //
                        //////////////////////////////////////////
                        //p_add_best = machine_add_u32_sse2;
                        //p_sub_best = machine_sub_u32_sse2;
            
                        #ifdef VECTORIZE_BUILD_WITH_SSE42
            
                            ////////////////////////////////////////////
                            // Best double word functions for SSE 4.2 //
                            ////////////////////////////////////////////
                            // TODO:
                            
                            #ifdef VECTORIZE_BUILD_WITH_AVX
            
                                ////////////////////////////////////////
                                // Best double word functions for AVX //
                                ////////////////////////////////////////
                                //p_add_best = machine_add_u32_avx;
                                //p_sub_best = machine_sub_u32_avx;
            
                                p_and_best = machine_and_avx;
                                p_orr_best = machine_or_avx;
                                p_xor_best = machine_xor_avx;
            
                                #ifdef VECTORIZE_BUILD_WITH_AVX2
            
                                    //////////////////////////////////////////
                                    // Best double word functions for AVX 2 //
                                    //////////////////////////////////////////
                                    //p_add_best = machine_add_u32_avx2;
                                    //p_sub_best = machine_sub_u32_avx2;
            
                                    //p_max_best = machine_max_u32_avx2;
                                    //p_min_best = machine_min_u32_avx2;
            
                                    p_and_best = machine_and_avx2;
                                    p_orr_best = machine_or_avx2;
                                    p_xor_best = machine_xor_avx2;
            
                                    #ifdef VECTORIZE_BUILD_WITH_AVX512_FOUNDATION 
            
                                        ////////////////////////////////////////////
                                        // Best double word functions for AVX 512 //
                                        ////////////////////////////////////////////
            
                                        #ifdef VECTORIZE_BUILD_WITH_AVX512_VECTOR_LENGTH
                                            #ifdef VECTORIZE_BUILD_WITH_AVX512_DOUBLE_QUAD_WORD

                                                //////////////////////////////////////////////////////
                                                // Best double word functions for AVX 512 + VL + DQ //
                                                //////////////////////////////////////////////////////

                                                p_add_best = machine_add_u8_avx512;
                                                p_sub_best = machine_sub_u8_avx512;

                                                p_max_best = machine_max_u32_avx512;
                                                p_min_best = machine_min_u32_avx512;

                                                p_and_best = machine_and_avx512;
                                                p_orr_best = machine_or_avx512;
                                                p_xor_best = machine_xor_avx512;
                                            #endif
                                        #endif
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            }
            break;

        // Machine is processing quad words
        case 8:

            {

                // Set the best quad word operations
                {
                    
                }
            }
            break;
    }

    // Set the conversion matrix
    {
                            
        // Platform dependent implementation
        #ifdef VECTORIZE_BUILD_WITH_INTEGRAL
        
            ////////////////////////////////////////////
            // Best conversion functions for integral //
            ////////////////////////////////////////////

            p_i8_i16_best  = machine_conv_8_16_;
            p_i8_i32_best  = machine_conv_8_32_;
            p_i8_i64_best  = machine_conv_8_64_;
            p_i8_f32_best  = machine_conv_8_f32_;
            p_i8_f64_best  = machine_conv_8_f64_;

            p_i16_i8_best  = machine_conv_16_8_;
            p_i16_i32_best = machine_conv_16_32_;
            p_i16_i64_best = machine_conv_16_64_;
            p_i16_f32_best = machine_conv_16_f32_;
            p_i16_f64_best = machine_conv_16_f64_;

            p_i32_i8_best  = machine_conv_32_8_;
            p_i32_i16_best = machine_conv_32_16_;
            p_i32_i64_best = machine_conv_32_64_;
            p_i32_f32_best = machine_conv_32_f32_;
            p_i32_f64_best = machine_conv_32_f64_;

            p_i64_i8_best  = machine_conv_64_8_;
            p_i64_i16_best = machine_conv_64_16_;
            p_i64_i32_best = machine_conv_64_32_;
            p_i64_f32_best = machine_conv_64_f32_;
            p_i64_f64_best = machine_conv_64_f64_;

            p_f32_i8_best  = machine_conv_f32_8_;
            p_f32_i16_best = machine_conv_f32_16_;
            p_f32_i32_best = machine_conv_f32_32_;
            p_f32_i64_best = machine_conv_f32_64_;
            p_f32_f64_best = machine_conv_f32_f64_;

            p_f64_i8_best  = machine_conv_f64_8_;
            p_f64_i16_best = machine_conv_f64_16_;
            p_f64_i32_best = machine_conv_f64_32_;
            p_f64_i64_best = machine_conv_f64_64_;
            p_f64_f32_best = machine_conv_f64_f32_;
        
            #ifdef VECTORIZE_BUILD_WITH_SSE2
        
                /////////////////////////////////////////
                // Best conversion functions for SSE 2 //
                /////////////////////////////////////////
                        
                #ifdef VECTORIZE_BUILD_WITH_SSE42
        
                    ///////////////////////////////////////////
                    // Best conversion functions for SSE 4.2 //
                    ///////////////////////////////////////////

                    #ifdef VECTORIZE_BUILD_WITH_AVX
        
                        ///////////////////////////////////////
                        // Best conversion functions for AVX //
                        ///////////////////////////////////////
                                
                        #ifdef VECTORIZE_BUILD_WITH_AVX2
        
                            /////////////////////////////////////////
                            // Best conversion functions for AVX 2 //
                            /////////////////////////////////////////
                                    
                            #ifdef VECTORIZE_BUILD_WITH_AVX512_FOUNDATION 
        
                                ///////////////////////////////////////////
                                // Best conversion functions for AVX 512 //
                                ///////////////////////////////////////////
        
                                #ifdef VECTORIZE_BUILD_WITH_AVX512_VECTOR_LENGTH
                                    #ifdef VECTORIZE_BUILD_WITH_AVX512_BYTE_WORD
                                        
                                    #endif

                                    #ifdef VECTORIZE_BUILD_WITH_AVX512_DWORD_QWORD
                                        
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            #endif
        #endif  
    }

    // Populate the machine at the parameter pointer
    *p_machine = (machine)
    {
        .program.p_instructions    = p_instructions,
        .program.instruction_count = _instruction_count,
        .data = (data_stream *[4]) {
            0,
            VECTORIZE_REALLOC(0, sizeof(data_stream) * 8),
            VECTORIZE_REALLOC(0, sizeof(data_stream) * 8),
            VECTORIZE_REALLOC(0, sizeof(data_stream) * 8)
        },
        .operation =
        {
            .pfn_add = p_add_best,
            .pfn_sub = p_sub_best,
            .pfn_mul = p_mul_best,
            .pfn_div = p_div_best,
            .pfn_rcp = p_rcp_best,
            .pfn_sqt = p_sqt_best,
            .pfn_str = p_str_best,
            .pfn_end = p_end_best,
            .pfn_rsq = p_rsq_best,
            .pfn_max = p_max_best,
            .pfn_min = p_min_best,
            .pfn_and = p_and_best,
            .pfn_orr = p_orr_best,
            .pfn_xor = p_xor_best,
            .pfn_shr = p_shr_best,
            .pfn_shl = p_shl_best
        },
        .conversion_functions = (size_t (*[6][6])(void *, void *)) { 0 },
        .operation_functions = (size_t (*[16])(void *, void *, void *))
        {
            p_add_best,
            p_sub_best,
            p_mul_best,
            p_div_best,
            p_rcp_best,
            p_sqt_best,
            p_str_best,
            p_end_best,
            p_rsq_best,
            p_max_best,
            p_min_best,
            p_and_best,
            p_orr_best,
            p_xor_best,
            p_shr_best,
            p_shl_best
        }
    };

    p_machine->conversion_functions[0][0] = 0;
    p_machine->conversion_functions[0][1] = p_i8_i16_best;
    p_machine->conversion_functions[0][2] = p_i8_i32_best;
    p_machine->conversion_functions[0][3] = p_i8_i64_best;
    p_machine->conversion_functions[0][4] = p_i8_f32_best;
    p_machine->conversion_functions[0][5] = p_i8_f64_best;

    p_machine->conversion_functions[1][0] = p_i16_i8_best;
    p_machine->conversion_functions[1][1] = 0;
    p_machine->conversion_functions[1][2] = p_i16_i32_best;
    p_machine->conversion_functions[1][3] = p_i16_i64_best;
    p_machine->conversion_functions[1][4] = p_i16_f32_best;
    p_machine->conversion_functions[1][5] = p_i16_f64_best;

    p_machine->conversion_functions[2][0] = p_i32_i8_best;
    p_machine->conversion_functions[2][1] = p_i32_i16_best;
    p_machine->conversion_functions[2][2] = 0;
    p_machine->conversion_functions[2][3] = p_i32_i64_best;
    p_machine->conversion_functions[2][4] = p_i32_f32_best;
    p_machine->conversion_functions[2][5] = p_i32_f64_best;

    p_machine->conversion_functions[3][0] = p_i64_i8_best;
    p_machine->conversion_functions[3][1] = p_i64_i16_best;
    p_machine->conversion_functions[3][2] = p_i64_i32_best;
    p_machine->conversion_functions[3][3] = 0;
    p_machine->conversion_functions[3][4] = p_i64_f32_best;
    p_machine->conversion_functions[3][5] = p_i64_f64_best;

    p_machine->conversion_functions[4][0] = p_f32_i8_best;
    p_machine->conversion_functions[4][1] = p_f32_i16_best;
    p_machine->conversion_functions[4][2] = p_f32_i32_best;
    p_machine->conversion_functions[4][3] = p_f32_i64_best;
    p_machine->conversion_functions[4][4] = 0;
    p_machine->conversion_functions[4][5] = p_f32_f64_best;

    p_machine->conversion_functions[5][0] = p_f64_i8_best;
    p_machine->conversion_functions[5][1] = p_f64_i16_best;
    p_machine->conversion_functions[5][2] = p_f64_i32_best;
    p_machine->conversion_functions[5][3] = p_f64_i64_best;
    p_machine->conversion_functions[5][4] = p_f64_f32_best;
    p_machine->conversion_functions[5][5] = 0;
    // Success
    return 1;
}

int machine_print_program ( machine _machine )
{

    putchar('\n');

    // Iterate over each instruction
    for (size_t i = 0; i < _machine.program.instruction_count; i++)
    {
        
        // Initialized data
        u16         _instruction_bin = _machine.program.p_instructions[i];
        instruction _instruction     = { 0 };

        // Decode the instruction binary
        instruction_decode(&_instruction, _instruction_bin);

        // Print the instruction
        instruction_print(_instruction);

        // New line
        putchar('\n');
    }

    putchar('\n');

    // Success
    return 1;
}

int machine_add ( machine *p_machine, data_stream *a, data_stream *b )
{

    // Argument check
    if ( p_machine == (void *) 0 ) goto no_machine;
    //if ( a         == (void *) 0 ) goto no_op1;
    //if ( b         == (void *) 0 ) goto no_op2;
    
    // Initialized data
    char *p_a  = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\0", //p_a = &((u8 *)a->data)[p_machine->index * a->stride],
         *p_b  = "                                                                                                                                \0";
    char *DATA = VECTORIZE_REALLOC(0, sizeof(char)*129);

    // TODO: Remove this stub
    DATA[128]='\0';

    p_a += 64;
    p_a =  (void *) (size_t) ( ( (size_t)(p_a) ) & 0xFFFFFFFFFFFFFFC0  );

    p_b += 64;
    p_b =  (void *) (size_t) ( ( (size_t)(p_b) ) & 0xFFFFFFFFFFFFFFC0  );

    DATA += 64;
    DATA =  (void *) (size_t) ( ( (size_t)(DATA) ) & 0xFFFFFFFFFFFFFFC0  );

    
    // TODO: Get a pointer to DATA 
    // TODO: Get a pointer to A 
    // TODO: Get a pointer to B 

    // NOTE: parameters to pfn_add must be aligned correctly.
    // That means:
    // 
    // AVX 512  : 512-bit register : 64 bytes 
    // AVX 2    : 256-bit register : 32 bytes 
    // AVX      : 128-bit register : 16 bytes 
    // SSE 4.2  : 128-bit register : 16 bytes 
    // SSE 2    : 128-bit register : 16 bytes 
    // INTEGRAL : 64-bit register  : 8 bytes  

    // Execute the add instruction
    (size_t)p_machine->operation.pfn_add(DATA, p_b, p_a);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_machine:
                #ifndef NDEBUG
                    printf("[vectorize] Null pointer provided for parameter \"p_machine\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error 
                return 0;

            no_op1:
                #ifndef NDEBUG
                    printf("[vectorize] Null pointer provided for parameter \"a\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error 
                return 0;

            no_op2:
                #ifndef NDEBUG
                    printf("[vectorize] Null pointer provided for parameter \"b\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error 
                return 0;
        }
    }
}

int machine_tick ( machine *p_machine )
{

    // Argument check
    if ( p_machine == (void *) 0 ) goto no_machine;

    // Initialized data
    u16          instruction_bin = p_machine->program.p_instructions[p_machine->program.program_counter];
    instruction  _instruction    = { 0 };
    data_stream *a               = 0,
                *b               = 0;

    // Get the in/out/var buffer
    if ( _instruction.operand_1.operand_type)
        a = p_machine->data[_instruction.operand_1.operand_type];
    
    // Get the context
    else
        a = p_machine->context;

    // Get the in/var buffer
    if ( _instruction.operand_2.operand_type)
        b = p_machine->data[_instruction.operand_2.operand_type];

    // Get the context
    else
        b = p_machine->context;

    // Increment the instruction counter
    p_machine->program.program_counter++;

    // Decode the instruction
    instruction_decode(&_instruction, instruction_bin);

    // Print the instruction
    instruction_print(_instruction);
    putchar('\n');
    fflush(stdout);

    size_t (*operation_functions)(void *p_result, void *a, void *b) = p_machine->operation_functions[_instruction.operation_type];

    // Process the instruction
    switch (_instruction.operation_type)
    {
        case VECTORIZE_OPERATION_ADD:
            machine_add(p_machine, a, b);
            break;
        case VECTORIZE_OPERATION_SUB:
            break;
        case VECTORIZE_OPERATION_MUL:
            break;
        case VECTORIZE_OPERATION_DIV:
            break;
        case VECTORIZE_OPERATION_RCP:
            break;
        case VECTORIZE_OPERATION_SQT:
            break;
        case VECTORIZE_OPERATION_STR:
            break;

        case VECTORIZE_OPERATION_END:
            p_machine->is_running = false;
            break;
    }

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_machine:
                #ifndef NDEBUG
                    printf("[Vectorize] Null pointer provided for \"p_machine\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

        }
    }
}

int machine_run ( machine *p_machine )
{

    // Argument check
    if ( p_machine == (void *) 0 ) goto no_machine;
    
    // Flip the running bit
    p_machine->is_running = true;
    
    // Start running the machine
    while ( p_machine->is_running )

        // One clock cycle
        machine_tick(p_machine);
    
    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_machine:
                #ifndef NDEBUG
                    printf("[vectorize] Null pointer provided for parameter \"p_machine\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

//////////////
// Integral //
//////////////

// Add
size_t machine_add_u8_  ( void *p_result, void *a, void *b )
{

    // Add
    *(u8 *)p_result = *(u8 *)a + *(u8 *)b;

    // Success
    return 1;
}
size_t machine_add_u16_ ( void *p_result, void *a, void *b )
{

    // Add
    *(u16 *)p_result = *(u16 *)a + *(u16 *)b;

    // Success
    return 1;
}
size_t machine_add_u32_ ( void *p_result, void *a, void *b )
{

    // Add
    *(u32 *)p_result = *(u32 *)a + *(u32 *)b;

    // Success
    return 1;
}
size_t machine_add_u64_ ( void *p_result, void *a, void *b )
{

    // Add
    *(u64 *)p_result = *(u64 *)a + *(u64 *)b;

    // Success
    return 1;
}
size_t machine_add_f32_ ( void *p_result, void *a, void *b )
{

    // Add
    *(f32 *)p_result = *(f32 *)a + *(f32 *)b;

    // Success
    return 1;
}
size_t machine_add_f64_ ( void *p_result, void *a, void *b )
{

    // Add
    *(f64 *)p_result = *(f64 *)a + *(f64 *)b;

    // Success
    return 1;
}

// Sub
size_t machine_sub_u8_  ( void *p_result, void *a, void *b )
{

    // Sub
    *(u8 *)p_result = *(u8 *)a - *(u8 *)b;

    // Success
    return 1;
}
size_t machine_sub_u16_ ( void *p_result, void *a, void *b )
{

    // Sub
    *(u16 *)p_result = *(u16 *)a - *(u16 *)b;

    // Success
    return 1;
}
size_t machine_sub_u32_ ( void *p_result, void *a, void *b )
{

    // Sub
    *(u32 *)p_result = *(u32 *)a - *(u32 *)b;

    // Success
    return 1;
}
size_t machine_sub_u64_ ( void *p_result, void *a, void *b )
{

    // Sub
    *(u64 *)p_result = *(u64 *)a - *(u64 *)b;

    // Success
    return 1;
}
size_t machine_sub_f32_ ( void *p_result, void *a, void *b )
{

    // Sub
    *(f32 *)p_result = *(f32 *)a - *(f32 *)b;

    // Success
    return 1;
}
size_t machine_sub_f64_ ( void *p_result, void *a, void *b )
{

    // Sub
    *(f64 *)p_result = *(f64 *)a - *(f64 *)b;

    // Success
    return 1;
}

// Mul
size_t machine_mul_u8_  ( void *p_result, void *a, void *b )
{

    // Mul
    *(u8 *)p_result = *(u8 *)a * *(u8 *)b;

    // Success
    return 1;
}
size_t machine_mul_u16_ ( void *p_result, void *a, void *b )
{

    // Mul
    *(u16 *)p_result = *(u16 *)a * *(u16 *)b;

    // Success
    return 1;
}
size_t machine_mul_u32_ ( void *p_result, void *a, void *b )
{

    // Mul
    *(u32 *)p_result = *(u32 *)a * *(u32 *)b;

    // Success
    return 1;
}
size_t machine_mul_u64_ ( void *p_result, void *a, void *b )
{

    // Mul
    *(u64 *)p_result = *(u64 *)a * *(u64 *)b;

    // Success
    return 1;
}
size_t machine_mul_f32_ ( void *p_result, void *a, void *b )
{

    // Mul
    *(f32 *)p_result = *(f32 *)a * *(f32 *)b;

    // Success
    return 1;
}
size_t machine_mul_f64_ ( void *p_result, void *a, void *b )
{

    // Mul
    *(f64 *)p_result = *(f64 *)a * *(f64 *)b;

    // Success
    return 1;
}

// Div
size_t machine_div_u8_  ( void *p_result, void *a, void *b )
{

    // Div
    *(u8 *)p_result = *(u8 *)a / *(u8 *)b;

    // Success
    return 1;
}
size_t machine_div_u16_ ( void *p_result, void *a, void *b )
{

    // Div
    *(u16 *)p_result = *(u16 *)a / *(u16 *)b;

    // Success
    return 2;
}
size_t machine_div_u32_ ( void *p_result, void *a, void *b )
{

    // Div
    *(u32 *)p_result = *(u32 *)a / *(u32 *)b;

    // Success
    return 4;
}
size_t machine_div_u64_ ( void *p_result, void *a, void *b )
{

    // Div
    *(u64 *)p_result = *(u64 *)a / *(u64 *)b;

    // Success
    return 8;
}
size_t machine_div_f32_ ( void *p_result, void *a, void *b )
{

    // Div
    *(f32 *)p_result = *(f32 *)a / *(f32 *)b;

    // Success
    return 4;
}
size_t machine_div_f64_ ( void *p_result, void *a, void *b )
{

    // Div
    *(f64 *)p_result = *(f64 *)a / *(f64 *)b;

    // Success
    return 8;
}

// Rcp

// Sqt

// Max
size_t machine_max_u8_  ( void *p_result, void *a, void *b )
{

    // Max
    *(u8 *)p_result = ( *(u8 *)a > *(u8 *)b ) ? *(u8 *)a : *(u8 *)b;

    // Success
    return 1;
}
size_t machine_max_u16_ ( void *p_result, void *a, void *b )
{

    // Max
    *(u16 *)p_result = ( *(u16 *)a > *(u16 *)b ) ? *(u16 *)a : *(u16 *)b;

    // Success
    return 2;
}
size_t machine_max_u32_ ( void *p_result, void *a, void *b )
{

    // Max
    *(u32 *)p_result = ( *(u32 *)a > *(u32 *)b ) ? *(u32 *)a : *(u32 *)b;

    // Success
    return 4;
}
size_t machine_max_u64_ ( void *p_result, void *a, void *b )
{

    // Max
    *(u64 *)p_result = ( *(u64 *)a > *(u64 *)b ) ? *(u64 *)a : *(u64 *)b;

    // Success
    return 8;
}
size_t machine_max_f32_ ( void *p_result, void *a, void *b )
{

    // Max
    *(f32 *)p_result = ( *(f32 *)a > *(f32 *)b ) ? *(f32 *)a : *(f32 *)b;

    // Success
    return 4;
}
size_t machine_max_f64_ ( void *p_result, void *a, void *b )
{

    // Max
    *(f64 *)p_result = ( *(f64 *)a > *(f64 *)b ) ? *(f64 *)a : *(f64 *)b;

    // Success
    return 8;
}

// Min
size_t machine_min_u8_  ( void *p_result, void *a, void *b )
{

    // Min
    *(u8 *)p_result = ( *(u8 *)a < (u8 *)b ) ? *(u8 *)a : *(u8 *)b;

    // Success
    return 1;
}
size_t machine_min_u16_ ( void *p_result, void *a, void *b )
{

    // Min
    *(u16 *)p_result = ( *(u16 *)a < *(u16 *)b ) ? *(u16 *)a : *(u16 *)b;

    // Success
    return 2;
}
size_t machine_min_u32_ ( void *p_result, void *a, void *b )
{

    // Min
    *(u32 *)p_result = ( *(u32 *)a < *(u32 *)b ) ? *(u32 *)a : *(u32 *)b;

    // Success
    return 4;
}
size_t machine_min_u64_ ( void *p_result, void *a, void *b )
{

    // Min
    *(u64 *)p_result = ( *(u64 *)a < *(u64 *)b ) ? *(u64 *)a : *(u64 *)b;

    // Success
    return 8;
}
size_t machine_min_f32_ ( void *p_result, void *a, void *b )
{

    // Min
    *(f32 *)p_result = ( *(f32 *)a < *(f32 *)b ) ? *(f32 *)a : *(f32 *)b;

    // Success
    return 4;
}
size_t machine_min_f64_ ( void *p_result, void *a, void *b )
{

    // Min
    *(f64 *)p_result = ( *(f64 *)a < *(f64 *)b ) ? *(f64 *)a : *(f64 *)b;

    // Success
    return 8;
}

// And
size_t machine_and_u8_  ( void *p_result, void *a, void *b )
{

    // Max
    *(u8 *)p_result = *(u8 *)a & *(u8 *)b;

    // Success
    return 1;
}
size_t machine_and_u16_ ( void *p_result, void *a, void *b )
{

    // Max
    *(u16 *)p_result = *(u16 *)a & *(u16 *)b;

    // Success
    return 2;
}
size_t machine_and_u32_ ( void *p_result, void *a, void *b )
{

    // Max
    *(u32 *)p_result = *(u32 *)a & *(u32 *)b;

    // Success
    return 4;
}
size_t machine_and_u64_ ( void *p_result, void *a, void *b )
{

    // Max
    *(u64 *)p_result = *(u64 *)a & *(u64 *)b;

    // Success
    return 8;
}
size_t machine_and_f32_ ( void *p_result, void *a, void *b )
{

    // Max
    *(f32 *)p_result = *(u32 *)a & *(u32 *)b;

    // Success
    return 4;
}
size_t machine_and_f64_ ( void *p_result, void *a, void *b )
{

    // Max
    *(f64 *)p_result = *(u64 *)a & *(u64 *)b;

    // Success
    return 8;
}

// Or
size_t machine_or_u8_   ( void *p_result, void *a, void *b )
{

    // Or
    *(u8 *)p_result = *(u8 *)a | *(u8 *)b;

    // Success
    return 1;
}
size_t machine_or_u16_  ( void *p_result, void *a, void *b )
{

    // Or
    *(u16 *)p_result = *(u16 *)a | *(u16 *)b;

    // Success
    return 2;
}
size_t machine_or_u32_  ( void *p_result, void *a, void *b )
{

    // Or
    *(u32 *)p_result = *(u32 *)a | *(u32 *)b;

    // Success
    return 4;
}
size_t machine_or_u64_  ( void *p_result, void *a, void *b )
{

    // Or
    *(u64 *)p_result = *(u64 *)a | *(u64 *)b;

    // Success
    return 8;
}
size_t machine_or_f32_  ( void *p_result, void *a, void *b )
{

    // Or
    *(f32 *)p_result = *(u32 *)a | *(u32 *)b;

    // Success
    return 4;
}
size_t machine_or_f64_  ( void *p_result, void *a, void *b )
{

    // Or
    *(f64 *)p_result = *(u64 *)a | *(u64 *)b;

    // Success
    return 8;
}

// Xor
size_t machine_xor_u8_  ( void *p_result, void *a, void *b )
{

    // Xor
    *(u8 *)p_result = *(u8 *)a ^ *(u8 *)b;

    // Success
    return 1;
}
size_t machine_xor_u16_ ( void *p_result, void *a, void *b )
{

    // Xor
    *(u16 *)p_result = *(u16 *)a ^ *(u16 *)b;

    // Success
    return 2;
}
size_t machine_xor_u32_ ( void *p_result, void *a, void *b )
{

    // Xor
    *(u32 *)p_result = *(u32 *)a ^ *(u32 *)b;

    // Success
    return 4;
}
size_t machine_xor_u64_ ( void *p_result, void *a, void *b )
{

    // Xor
    *(u64 *)p_result = *(u64 *)a ^ *(u64 *)b;

    // Success
    return 8;
}
size_t machine_xor_f32_ ( void *p_result, void *a, void *b )
{

    // Xor
    *(f32 *)p_result = *(u32 *)a ^ *(u32 *)b;

    // Success
    return 4;
}
size_t machine_xor_f64_ ( void *p_result, void *a, void *b )
{

    // Xor
    *(f64 *)p_result = *(u64 *)a ^ *(u64 *)b;

    // Success
    return 8;
}

// Shr

// Shl

// 8-bit -> X
size_t machine_conv_8_16_  ( void *p_result, void *a )
{
    
    // 8-bit -> 16-bit
    *(u16*)p_result = *(u8*)a;

    // Success   
    return 1;
}
size_t machine_conv_8_32_  ( void *p_result, void *a )
{
    
    // 8-bit -> 32-bit
    *(u32*)p_result = *(u8*)a;

    // Success   
    return 1;
}
size_t machine_conv_8_64_  ( void *p_result, void *a )
{
    
    // 8-bit -> 64-bit
    *(u64*)p_result = *(u8*)a;

    // Success   
    return 1;
}
size_t machine_conv_8_f32_ ( void *p_result, void *a )
{
    
    // 8-bit -> 32-bit float
    *(f32*)p_result = *(u8*)a;

    // Success   
    return 1;
}
size_t machine_conv_8_f64_ ( void *p_result, void *a )
{
    
    // 8-bit -> 64-bit float
    *(f64*)p_result = *(u8*)a;

    // Success   
    return 1;
}

// 16-bit -> X
size_t machine_conv_16_8_   ( void *p_result, void *a )
{
    
    // 16-bit -> 8-bit
    *(u8*)p_result = *(u16*)a;

    // Success   
    return 1;
}
size_t machine_conv_16_32_  ( void *p_result, void *a )
{
    
    // 16-bit -> 32-bit
    *(u32*)p_result = *(u16*)a;

    // Success   
    return 1;
}
size_t machine_conv_16_64_  ( void *p_result, void *a )
{
    
    // 16-bit -> 64-bit
    *(u64*)p_result = *(u16*)a;

    // Success   
    return 1;
}
size_t machine_conv_16_f32_ ( void *p_result, void *a )
{
    
    // 16-bit -> 32-bit float
    *(f32*)p_result = *(u16*)a;

    // Success   
    return 1;
}
size_t machine_conv_16_f64_ ( void *p_result, void *a )
{
    
    // 16-bit -> 64-bit float
    *(f64*)p_result = *(u16*)a;

    // Success   
    return 1;
}

// 32-bit -> X
size_t machine_conv_32_8_   ( void *p_result, void *a )
{

    // 32-bit -> 8-bit 
    *(u8*)p_result = *(u32*)a;

    // Success   
    return 1;
}
size_t machine_conv_32_16_  ( void *p_result, void *a )
{

    // 32-bit -> 16-bit 
    *(u16*)p_result = *(u32*)a;

    // Success   
    return 1;
}
size_t machine_conv_32_64_  ( void *p_result, void *a )
{
    
    // 32-bit -> 64-bit 
    *(u64*)p_result = *(u32*)a;

    // Success   
    return 1;
}
size_t machine_conv_32_f32_ ( void *p_result, void *a )
{
    
    // 32-bit -> 32-bit float
    *(f32*)p_result = *(u32*)a;

    // Success   
    return 1;
}
size_t machine_conv_32_f64_ ( void *p_result, void *a )
{
    
    // 32-bit -> 64-bit float
    *(f64*)p_result = *(u32*)a;

    // Success   
    return 1;
}

// 64-bit -> X
size_t machine_conv_64_8_    ( void *p_result, void *a )
{
    
    // 64-bit -> 8-bit
    *(u8*)p_result = *(u64*)a;

    // Success   
    return 1;
}
size_t machine_conv_64_16_   ( void *p_result, void *a )
{
    
    // 64-bit -> 16-bit
    *(u16*)p_result = *(u64*)a;

    // Success   
    return 1;
}
size_t machine_conv_64_32_   ( void *p_result, void *a )
{
    
    // 64-bit -> 32-bit
    *(u32*)p_result = *(u64*)a;

    // Success   
    return 1;
}
size_t machine_conv_64_f32_  ( void *p_result, void *a )
{
    
    // 64-bit -> 32-bit float
    *(f32*)p_result = *(u64*)a;

    // Success   
    return 1;
}
size_t machine_conv_64_f64_  ( void *p_result, void *a )
{
    
    // 64-bit -> 64-bit float
    *(f64*)p_result = *(u64*)a;

    // Success   
    return 1;
}

// 32-bit -> X
size_t machine_conv_f32_8_   ( void *p_result, void *a )
{
    
    // 32-bit float -> 8-bit
    *(u8*)p_result = *(f32*)a;

    // Success   
    return 1;
}
size_t machine_conv_f32_16_  ( void *p_result, void *a )
{
    
    // 32-bit float -> 16-bit
    *(u16*)p_result = *(f32*)a;

    // Success   
    return 1;
}
size_t machine_conv_f32_32_  ( void *p_result, void *a )
{
    
    // 32-bit float -> 32-bit
    *(u32*)p_result = *(f32*)a;

    // Success   
    return 1;
}
size_t machine_conv_f32_64_  ( void *p_result, void *a )
{
    
    // 32-bit float -> 64-bit
    *(f32*)p_result = *(f32*)a;

    // Success   
    return 1;
}
size_t machine_conv_f32_f64_ ( void *p_result, void *a )
{
    
    // 32-bit float -> 64-bit float
    *(f64*)p_result = *(f32*)a;

    // Success   
    return 1;
}

// 64-bit -> X
size_t machine_conv_f64_8_   ( void *p_result, void *a )
{
    
    // 64-bit float -> 8-bit
    *(u8*)p_result = *(f64*)a;

    // Success   
    return 1;
}
size_t machine_conv_f64_16_  ( void *p_result, void *a )
{
    
    // 64-bit float -> 16-bit
    *(u16*)p_result = *(f64*)a;

    // Success   
    return 1;
}
size_t machine_conv_f64_32_  ( void *p_result, void *a )
{
    
    // 64-bit float -> 32-bit
    *(u32*)p_result = *(f64*)a;

    // Success   
    return 1;
}
size_t machine_conv_f64_64_  ( void *p_result, void *a )
{
    
    // 64-bit float -> 64-bit
    *(u64*)p_result = *(f64*)a;

    // Success   
    return 1;
}
size_t machine_conv_f64_f32_ ( void *p_result, void *a )
{
    
    // 64-bit float -> 32-bit float
    *(f32*)p_result = *(f64*)a;

    // Success   
    return 1;
}
