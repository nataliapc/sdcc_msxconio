#include "conio.h"


/**
 * Deletes the line where the cursor is located and moves all lower lines
 * up one line. The delline function works in the active text window.
 */
void delline()
{
	cputs(VT_DELLINE);
}
