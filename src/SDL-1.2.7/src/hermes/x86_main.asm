;
; x86 format converters for HERMES
; Some routines Copyright (c) 1998 Christian Nentwich (brn@eleet.mcb.at)
; This source code is licensed under the GNU LGPL
; 
; Please refer to the file COPYING.LIB contained in the distribution for
; licensing conditions		
;
; Most routines are (c) Glenn Fiedler (ptc@gaffer.org), used with permission
; 

BITS 32

GLOBAL _ConvertX86
GLOBAL _x86return
	
GLOBAL _Hermes_X86_CPU


SECTION .data
	
cpu_flags dd 0
	
		
SECTION .text
		
;; _ConvertX86:	 
;; [ESP+8] ConverterInfo*
;; --------------------------------------------------------------------------
;; ConverterInfo (ebp+..)
;;   0:	void *s_pixels
;;   4:	int s_width
;;   8:	int s_height
;;  12:	int s_add
;;  16:	void *d_pixels
;;  20:	int d_width
;;  24:	int d_height
;;  28:	int d_add
;;  32:	void (*converter_function)() 
;;  36: int32 *lookup
	
_ConvertX86:
	push ebp
	mov ebp,esp

; Save the registers used by the blitters, necessary for optimized code
	pusha

	mov eax,[ebp+8]

        cmp dword [eax+4],BYTE 0
	je endconvert
	
	mov ebp,eax
	
	mov esi,[ebp+0]
	mov edi,[ebp+16]
	
y_loop:	
	mov ecx,[ebp+4]

	jmp [ebp+32]

_x86return:	
	add esi,[ebp+12]
	add edi,[ebp+28]
	
	dec dword  [ebp+8]
	jnz y_loop

; Restore the registers used by the blitters, necessary for optimized code
	popa
	
	pop ebp

endconvert:	
	ret		



;; Hermes_X86_CPU returns the CPUID flags in eax
	
_Hermes_X86_CPU:
	pushfd
	pop eax
	
	mov ecx,eax
	
	xor eax,040000h
	push eax
	
	popfd
	pushfd

	pop eax
	xor eax,ecx
	jz .L1			; Processor is 386

	push ecx
	popfd

	mov eax,ecx
	xor eax,200000h

	push eax
	popfd
	pushfd

	pop eax
	xor eax,ecx
	je .L1
	
	pusha
	
	mov eax,1
	cpuid

	mov [cpu_flags],edx

	popa

	mov eax,[cpu_flags]

.L1:	
	ret
