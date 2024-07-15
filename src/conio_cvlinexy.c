#include "conio.h"


/**
 * cvlinexy
 * The function outputs a vertical line with the given length starting at a given 
 * position.
 * The character used to draw the vertical line is system dependent. If available, 
 * a line drawing character is used. Drawing a line that is partially off screen 
 * leads to undefined behaviour.
 */
void cvlinexy(unsigned char x, unsigned char y, unsigned char length)
{
	gotoxy(x, y);
	cvline(length);
}
