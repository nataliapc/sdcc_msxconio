#include "conio.h"
#include "conio_aux.h"


/**
 * This function clears the current text window and places the cursor in the
 * upper left corner: position (1,1).
 */
void clrscr()
{
	_fillVRAM(_current_text_info.vramCharMap, 0x800, 32);
	_fillVRAM(ADR_BLINK, 0xf0, 0);
	gotoxy(_current_text_info.winleft, _current_text_info.wintop);
}
