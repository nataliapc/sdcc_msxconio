#include "msx_const.h"
#include "conio.h"


/**
 * Checks if a pressed key is available. Any available keystrokes
 * can be retrieved with the getch or getche functions.
 * 
 * @return	The kbhit function returns 0 if no keystroke has been registered;
 * 			if one is available, then the returned value is
 * 			different from zero.
 */
bool kbhit()
{
	return ADDR_POINTER_BYTE(PUTPNT) != ADDR_POINTER_BYTE(GETPNT);
}
