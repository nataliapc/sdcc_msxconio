#include "conio.h"


/**
 * Reads 1 byte from the port indicated by the id_puerto argument.
 */
uint8_t inportb(uint8_t port) __naked __sdcccall(1)
{
	__asm
		ld c,a			; A = Param port
		in a,(c)
		ret				; Returns A
	__endasm;
}
