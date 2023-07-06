;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                 ;
; @file vectorize avx512.asm                                      ;
;                                                                 ;
; @author Jacob C Smith                                           ;
;                                                                 ;
; High performance AVX512 implementations of machine instructions ;
;                                                                 ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Code
section .text

;;;;;;;;;;;;;;;;;;;;
; Width operations ;
;;;;;;;;;;;;;;;;;;;;
global machine_and_avx512
machine_and_avx512:
;    ; Load A
;    vmovaps zmm1, zword [rdx] ; zmm1 <= rdx (a)
;
;    ; Load B
;    vmovaps zmm2, zword [r8] ; zmm2 <= r8 (b)
;
;    ; and 512 bits
;    vpand zmm0, zmm2, zmm1  ; zmm0 <= zmm1 & zmm2 (a & b)
;
;    ; Store the result of the and operation at the return pointer
;    vmovaps zword [rcx], zmm0 ; rcx <= zmm0 
;
;    ; Success
;    mov rax, 64

    ; Return
    ret

.end:

global machine_or_avx512
machine_or_avx512:
;; Load A
;vmovaps zmm1, zword [rdx] ; zmm1 <= rdx (a)
;
;; Load B
;vmovaps zmm2, zword [r8] ; zmm2 <= r8 (b)
;
;; or 512 bits
;vpor zmm0, zmm2, zmm1  ; zmm0 <= zmm1 | zmm2 (a | b)
;
;; Store the result of the or operation at the return pointer
;vmovaps zword [rcx], zmm0 ; rcx <= zmm0 
;
;; Success
;mov rax, 64
    
    ; Return
    ret

.end:

global machine_xor_avx512
machine_xor_avx512:
;    ; Load A
;    vmovaps zmm1, zword [rdx] ; zmm1 <= rdx (a)
;
;    ; Load B
;    vmovaps zmm2, zword [r8] ; zmm2 <= r8 (b)
;
;    ; xor 256 bits
;    vpxor zmm0, zmm2, zmm1  ; zmm0 <= zmm1 ^ zmm2 (a ^ b)
;
;    ; Store the result of the xor operation at the return pointer
;    vmovaps zword [rcx], zmm0 ; rcx <= zmm0 
;
;    ; Success
;    mov rax, 64
;    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;
; Byte operations ;
;;;;;;;;;;;;;;;;;;;

; Add 8-bit values
global machine_add_u8_avx512
machine_add_u8_avx512:

    ; Load A
    vmovaps zmm1, zword [rdx] ; zmm1 <= rdx (a)

    ; Load B
    vmovaps zmm2, zword [r8] ; zmm2 <= r8 (b)

    ; vec A + vec B as packed 8-bit values
    vpaddb zmm0, zmm2, zmm1  ; zmm0 <= zmm1 + zmm2 (a + b)

    ; Store the result of the add operation at the return pointer
    vmovaps zword [rcx], zmm0 ; rcx <= zmm0 

    ; Success
    mov rax, 64
    
    ; Return
    ret

.end:

; Subtract 8-bit values
global machine_sub_u8_avx512
machine_sub_u8_avx512:

    ; Load A
    vmovaps zmm1, zword [r8] ; zmm1 <= rcx (a)

    ; Load B
    vmovaps zmm2, zword [rdx] ; zmm2 <= rdx (b)

    ; vec A - vec B as packed 8-bit values
    vpsubb zmm0, zmm2, zmm1  ; zmm0 <= zmm1 + zmm2 (a - b)
    
    ; Store the result of the add operation at the return pointer
    vmovaps zword [rcx], zmm0 ; rcx <= zmm0 

    ; Success
    mov rax, 64
    
    ; Return
    ret

.end:

;;;;;;;;;;;;;;;;;;;
; Word operations ;
;;;;;;;;;;;;;;;;;;;

; TODO: Add 16-bit values
; ...

;;;;;;;;;;;;;;;;;;;;;;;;;;
; Double word operations ;
;;;;;;;;;;;;;;;;;;;;;;;;;;

; TODO: Add 32-bit values
; ...

;;;;;;;;;;;;;;;;;;;;;;;;
; Quad word operations ;
;;;;;;;;;;;;;;;;;;;;;;;;

; TODO: Add 64-bit values
; ...

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Single precision floating point operations ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; TODO: Add 32-bit floats
; ...

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Double precision floating point operations ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; TODO: Add 64-bit floats
; ...