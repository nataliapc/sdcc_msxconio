#include "msx_const.h"
#include "conio.h"


/**
 * Moves the text window cursor to the position specified by the x and y
 * coordinates. If the coordinates are not valid, then the call to the
 * gotoxy function is ignored.
 */
void gotoxy(uint8_t x, uint8_t y)
{
	if (x<1 || y<1) return;

	ADDR_POINTER_BYTE(CSRX)=x;
	ADDR_POINTER_BYTE(CSRY)=y;
}
