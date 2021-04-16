#include "msx_const.h"
#include "conio.h"


/**
 * TODO inportb
 * Lee 1 byte desde el puerto indicado por el argumento id_puerto.
 */
uint8_t inportb(uint8_t id_puerto) __naked __z88dk_fastcall
{
	__asm
		ld a,l

		in a,(c)

		ld l,a
		ret
	__endasm;
}
