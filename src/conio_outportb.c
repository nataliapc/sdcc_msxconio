#include "conio.h"


/**
 * Writes 1 byte to the output port specified by the port_id argument.
 */
void outportb(uint8_t port, uint8_t value) __naked __sdcccall(1)
{
	__asm
		ld c,a			; A = Param port
		ld a,l			; L = Param value

		out (c),a

		ret
	__endasm;
}
