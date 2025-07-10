#include "conio.h"


/**
 * This function clears all characters from the cursor position
 * to the end of the line within the current text window, without moving
 * the cursor position.
 */
void clreol(void)
{
	cputs(VT_CLREOL);
}
