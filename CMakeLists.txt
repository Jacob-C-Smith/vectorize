cmake_minimum_required (VERSION 3.26)

project ("vectorize" ASM_NASM C)

set(CMAKE_NASM_LINK_EXECUTABLE "ld <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CAN_USE_ASSEMBLER TRUE)

# Comment out for Debug mode
set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")
if ( NOT "${HAS_VECTORIZE}")
    message("[vectorize] Adding vectorize project")
    set(HAS_VECTORIZE true PARENT_SCOPE)
endif()

if (${IS_DEBUG_BUILD})
    add_compile_definitions(NDEBUG)
endif ()

#Adding inputfile to be able to detect files vis %include. Should use includes but documentation is poorly so use as flag
set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -i ${CMAKE_CURRENT_SOURCE_DIR}/src/asm/elf64/ -i ${CMAKE_CURRENT_SOURCE_DIR}/src/asm/macho64/")
enable_language(ASM_NASM)

set_source_files_properties("vectorize avx512.asm" PROPERTIES LANGUAGE ASM_NASM)
set_source_files_properties("vectorize avx2.asm" PROPERTIES LANGUAGE ASM_NASM)
set_source_files_properties("vectorize avx.asm" PROPERTIES LANGUAGE ASM_NASM)
set_source_files_properties("vectorize sse42.asm" PROPERTIES LANGUAGE ASM_NASM)
set_source_files_properties("vectorize sse2.asm" PROPERTIES LANGUAGE ASM_NASM)

# Add source to this project's executable.
add_executable (vectorize_example "main.c" "vectorize.c" "vectorize avx512.asm" "vectorize avx2.asm" "vectorize avx.asm" "vectorize sse42.asm" "vectorize sse2.asm")
target_include_directories(vectorize_example PUBLIC "include")
set_target_properties(vectorize_example PROPERTIES NASM_OBJ_FORMAT win64)

# Add source to the tester
add_executable (vectorize_test "vectorize test.c" "vectorize.c" "vectorize avx512.asm" "vectorize avx2.asm" "vectorize avx.asm" "vectorize sse42.asm" "vectorize sse2.asm")
target_include_directories(vectorize_test PUBLIC "include")
set_target_properties(vectorize_test PROPERTIES NASM_OBJ_FORMAT win64)

# Add source to this project's library
add_library (vectorize SHARED "vectorize.c" "vectorize avx512.asm" "vectorize avx2.asm" "vectorize avx.asm" "vectorize sse42.asm" "vectorize sse2.asm")
target_include_directories(vectorize PUBLIC include include/vectorize)
set_target_properties(vectorize PROPERTIES NASM_OBJ_FORMAT win64)
