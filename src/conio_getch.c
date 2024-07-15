#include "msx_const.h"
#include "conio.h"


/**
 * Reads a single character directly from the keyboard, without displaying
 * the character on the screen.
 * 
 * @return	Returns the character read from the keyboard.
 */
int getch() __naked __z88dk_fastcall
{
	__asm
		ld c,#INNOE
		DOSCALL

		ld h, #0		; Returns HL
		ret
	__endasm;
}
