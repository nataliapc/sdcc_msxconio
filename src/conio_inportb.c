#include "msx_const.h"
#include "conio.h"


/**
 * TODO inportb
 * Lee 1 byte desde el puerto indicado por el argumento id_puerto.
 */
uint8_t inportb(uint8_t port) __naked __z88dk_fastcall
{
	__asm
		ld c,l

		in a,(c)

		ld l,a
		ret
	__endasm;
}
