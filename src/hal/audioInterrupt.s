.global IntHandler6
.global _IntHandler6

IntHandler6:
_IntHandler6:
	pusha
	call _XAudioInterrupt
	mov $0x20, %al
	outb %al, $0x20
	popa
	iret
	 