.global IntHandler1
.global _IntHandler1

IntHandler1:
_IntHandler1:
	pusha
	call _XUSBInterrupt
	mov $0x20, %al
	outb %al, $0x20
	popa
	iret
	 