;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                               ;
; @file vectorize avx2.asm                                      ;
;                                                               ;
; @author Jacob C Smith                                         ;
;                                                               ;
; High performance AVX2 implementations of machine instructions ;
;                                                               ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Code
section .text

;;;;;;;;;;;;;;;;;;;;
; Width operations ;
;;;;;;;;;;;;;;;;;;;;
global machine_and_avx2
machine_and_avx2:
    ; Load A
    vmovaps ymm1, yword [rdx] ; ymm1 <= rdx (a)

    ; Load B
    vmovaps ymm2, yword [r8] ; ymm2 <= r8 (b)

    ; and 256 bits
    vpand ymm0, ymm2, ymm1  ; ymm0 <= ymm1 & ymm2 (a & b)

    ; Store the result of the and operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

global machine_or_avx2
machine_or_avx2:
    ; Load A
    vmovaps ymm1, yword [rdx] ; ymm1 <= rdx (a)

    ; Load B
    vmovaps ymm2, yword [r8] ; ymm2 <= r8 (b)

    ; or 256 bits
    vpor ymm0, ymm2, ymm1  ; ymm0 <= ymm1 | ymm2 (a | b)

    ; Store the result of the or operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

global machine_xor_avx2
machine_xor_avx2:
    ; Load A
    vmovaps ymm1, yword [rdx] ; ymm1 <= rdx (a)

    ; Load B
    vmovaps ymm2, yword [r8] ; ymm2 <= r8 (b)

    ; xor 256 bits
    vpxor ymm0, ymm2, ymm1  ; ymm0 <= ymm1 ^ ymm2 (a ^ b)

    ; Store the result of the xor operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;
; Byte operations ;
;;;;;;;;;;;;;;;;;;;

; Add 8-bit values
global machine_add_u8_avx2
machine_add_u8_avx2:

    ; Load A
    vmovaps ymm1, yword [rdx] ; ymm1 <= rdx (a)

    ; Load B
    vmovaps ymm2, yword [r8] ; ymm2 <= r8 (b)

    ; vec A + vec B as packed 8-bit values
    vpaddb ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a + b)

    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Subtract 8-bit values
global machine_sub_u8_avx2
machine_sub_u8_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 8-bit values
    vpsubb ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Max 8-bit values
global machine_max_u8_avx2
machine_max_u8_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 8-bit values
    vpmaxub ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Max 8-bit values
global machine_min_u8_avx2
machine_min_u8_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 8-bit values
    vpminub ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;
; Word operations ;
;;;;;;;;;;;;;;;;;;;

; Add 16-bit values
global machine_add_u16_avx2
machine_add_u16_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 16-bit values
    vpaddw ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Subtract 16-bit values
global machine_sub_u16_avx2
machine_sub_u16_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 16-bit values
    vpsubw ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Multiply 16-bit values
global machine_mul_u16_avx2
machine_mul_u16_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 16-bit values
    vpmullw ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a * b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;;;;;;;;
; Double word operations ;
;;;;;;;;;;;;;;;;;;;;;;;;;;

; Add 32-bit values
global machine_add_u32_avx2
machine_add_u32_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 32-bit values
    vpaddd ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;;;;;;
; Quad word operations ;
;;;;;;;;;;;;;;;;;;;;;;;;

; Add 64-bit values
global machine_add_u64_avx2
machine_add_u64_avx2:

    ; Load A
    vmovaps ymm1, yword [r8] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; vec A - vec B as packed 64-bit values
    vpaddd ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps yword [rcx], ymm0 ; rcx <= ymm0 

    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Add single precision floating point values
global machine_add_f32_avx2
machine_add_f32_avx2:

    ; Load A
    vmovaps ymm1, yword [rcx] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; Add A + B as packed single precision floating point values
    vaddps ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a + b)
    
    ; Success
    mov rax, 32
    
    ; Return
    ret

.end:

; Add double precision floating point values
global machine_add_f64_avx2
machine_add_f64_avx2:

    ; Load A
    vmovaps ymm1, yword [rcx] ; ymm1 <= rcx (a)

    ; Load B
    vmovaps ymm2, yword [rdx] ; ymm2 <= rdx (b)

    ; Add A + B as packed double precision floating point values
    vaddpd ymm0, ymm2, ymm1  ; ymm0 <= ymm1 + ymm2 (a + b)
    
    ; Success
    mov rax, 32
    
    ; Return
    ret

.end: