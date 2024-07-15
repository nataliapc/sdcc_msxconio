#include "conio.h"


/**
 * Inserts an empty line in the text window at the cursor position
 * using the current text background color. All lines below the
 * empty one are moved one line down, and the bottom line is moved
 * out of the window.
 */
void insline()
{
	cputs(VT_INSLINE);
}
