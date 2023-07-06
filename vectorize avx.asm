;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                              ;
; @file vectorize avx.asm                                      ;
;                                                              ;
; @author Jacob C Smith                                        ;
;                                                              ;
; High performance AVX implementations of machine instructions ;
;                                                              ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; 64-bit machines only
[BITS 64]

; Code
section .text

;;;;;;;;;;;;;;;;;;;;
; Width operations ;
;;;;;;;;;;;;;;;;;;;;
global machine_and_avx
machine_and_avx:
    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; and 128 bits
    vpand xmm0, xmm2, xmm1  ; xmm0 <= xmm1 & xmm2 (a & b)

    ; Store the result of the and operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end:

global machine_or_avx
machine_or_avx:
    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; or 128 bits
    vpor xmm0, xmm2, xmm1  ; xmm0 <= xmm1 | xmm2 (a | b)

    ; Store the result of the and operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end:

global machine_xor_avx
machine_xor_avx:
    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; xor 128 bits
    vpxor xmm0, xmm2, xmm1  ; xmm0 <= xmm1 ^ xmm2 (a ^ b)

    ; Store the result of the and operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;
; Byte operations ;
;;;;;;;;;;;;;;;;;;;

; Add 8-bit values
global machine_add_u8_avx
machine_add_u8_avx:

    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A + vec B as packed 8-bit values
    vpaddb xmm0, xmm2, xmm1  ; xmm0 <= xmm1 + xmm2 (a + b)

    ; Store the result of the add operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end: 

; Sub 8-bit values
global machine_sub_u8_avx
machine_sub_u8_avx:

    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A - vec B as packed 8-bit values
    vpsubb xmm0, xmm2, xmm1  ; xmm0 <= xmm1 - xmm2 (a - b)

    ; Store the result of the sub operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end: 

global machine_add_u16_avx
machine_add_u16_avx:

    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A + vec B as packed 16-bit values
    vpaddw xmm0, xmm2, xmm1

    ; Store the result of the add operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0

    ; Success
    mov rax, 16

    ; Return
    ret

.end:

global machine_add_u32_avx
machine_add_u32_avx:

    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A + vec B as packed 32-bit values
    vpaddd xmm0, xmm2, xmm1

    ; Store the result of the add operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0

    ; Success
    mov rax, 16

    ; Return
    ret

.end:

global machine_add_u64_avx
machine_add_u64_avx:

    ; Load A
    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A + vec B as packed 64-bit values
    vpaddq xmm0, xmm2, xmm1

    ; Store the result of the add operation at the return pointer
    vmovaps oword [rcx], xmm0 ; rcx <= xmm0

    ; Success
    mov rax, 16

    ; Return
    ret

.end:

global machine_add_f32_avx
machine_add_f32_avx:

;    ; Load A
;    vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)
;
;    ; Load B
;    vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)
;
;    ; vec A + vec B as packed 32-bit floats
;    vpaddx xmm0, xmm2, xmm1
;
;    ; Store the result of the add operation at the return pointer
;    vmovaps oword [rcx], xmm0 ; rcx <= xmm0
;
;    ; Success
;    mov rax, 16

    ; Return
    ret

.end:

global machine_add_f64_avx
machine_add_f64_avx:

;   ; Load A
;   vmovaps xmm1, oword [rdx] ; xmm1 <= rdx (a)
;   
;   ; Load B
;   vmovaps xmm2, oword [r8] ; xmm2 <= r8 (b)
;   
;   ; vec A + vec B as packed 64-bit floats
;   vpaddx xmm0, xmm2, xmm1
;   
;   ; Store the result of the add operation at the return pointer
;   vmovaps oword [rcx], xmm0 ; rcx <= xmm0
;   
;   ; Success
;   mov rax, 16

    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;
; Word operations ;
;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;
; Double word operations ;
;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;
; Quad word operations ;
;;;;;;;;;;;;;;;;;;;;;;;;

