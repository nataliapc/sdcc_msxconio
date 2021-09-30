#include "msx_const.h"
#include "conio.h"


/**
 * Escribe 1 byte al puerto de salida indicado por el argumento id_puerto.
 */
void outportb(uint8_t port, uint8_t value) __naked
{
	__asm
		pop af
		pop bc
		push bc
		push af
		ld a,b

		out (c),a

		ret
	__endasm;
}
