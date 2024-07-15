#include "msx_const.h"
#include "conio.h"


/**
 * Gets the y-coordinate of the current cursor position (within the
 * active text window).
 * 
 * @return	The wherey function returns an integer between 1 and the number
 * 			of rows in the current text mode.
 */
uint8_t wherey() __naked __sdcccall(1)
{
	__asm
		ld  a,(#CSRY)
		ret
	__endasm;
}
