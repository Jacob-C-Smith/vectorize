;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                ;
; @file vectorize sse2.asm                                       ;
;                                                                ;
; @author Jacob C Smith                                          ;
;                                                                ;
; High performance SSE 2 implementations of machine instructions ;
;                                                                ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[BITS 64]

; Code
section .text

;;;;;;;;;;;;;;;;;;;
; Byte operations ;
;;;;;;;;;;;;;;;;;;;

; Add 8-bit values
global machine_add_u8_sse2
machine_add_u8_sse2:

    ; Load A
    ;movaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    ;movaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A + vec B as packed 8-bit values
    ;addb xmm0, xmm2, xmm1  ; xmm0 <= xmm1 + xmm2 (a + b)

    ; Store the result of the add operation at the return pointer
    ;movaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end:

; Sub 8-bit values
global machine_sub_u8_sse2
machine_sub_u8_sse2:

    ; Load A
    ;movaps xmm1, oword [rdx] ; xmm1 <= rdx (a)

    ; Load B
    ;movaps xmm2, oword [r8] ; xmm2 <= r8 (b)

    ; vec A + vec B as packed 8-bit values
    ;subb xmm0, xmm2, xmm1  ; xmm0 <= xmm1 - xmm2 (a - b)

    ; Store the result of the sub operation at the return pointer
    ;movaps oword [rcx], xmm0 ; rcx <= xmm0 

    ; Success
    mov rax, 16
    
    ; Return
    ret

.end: