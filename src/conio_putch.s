; Displays a character, specified by the argument c, directly to the
; current text window. The putch function uses video directly to
; display characters. This is done by writing directly to the
; screen memory or by calling the BIOS, depending on the
; value of the global variable _directvideo. This function does not convert
; newline characters (\n) into the carriage return/newline pair (\r\n).
;
; @return	Returns the displayed character if successful; if an error occurs,
; 			then it returns EOF.


_putchar::
	ld a,l

;uint8_t putch(uint8_t c) __sdcccall(1);
_putch::
					; A = Param c
	cp #'\n'
	jr nz, .normalCharPutch

	ld e,#'\r'
	ld c,#0x02		;CONOUT
	push af
	call 5
	pop af

.normalCharPutch:
	ld e,a
	ld c,#0x02		;CONOUT
	jp 5			; Returns A
