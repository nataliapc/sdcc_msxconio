#include "conio.h"


/**
 * chlinexy
 * The function outputs a horizontal line with the given length starting at a given 
 * position.
 * The character used to draw the horizontal line is system dependent. If available, 
 * a line drawing character is used. Drawing a line that is partially off screen 
 * leads to undefined behaviour.
 */
void chlinexy(unsigned char x, unsigned char y, unsigned char length)
{
	gotoxy(x, y);
	chline(length);
}
