#include "msx_const.h"
#include "conio.h"


/**
 * Reads a single character directly from the keyboard, displaying such character
 * on the screen, directly to video.
 *
 * @return	The getche function returns the character read from the keyboard.
 */
int getche() __naked __z88dk_fastcall
{
	__asm
		ld c,#CONIN
		DOSCALL
		ld h, #0			; Returns HL
		ret
	__endasm;
}
