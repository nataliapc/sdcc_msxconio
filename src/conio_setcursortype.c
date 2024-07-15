#include "msx_const.h"
#include "conio.h"


/**
 * Selects the cursor appearance from three types. The cursor_type
 * argument indicates the type of cursor to select according to these:
 *     NOCURSOR     Disables the cursor
 *     NORMALCURSOR Normal cursor: the underscore character
 *     SOLIDCURSOR  Cursor is a filled square
 */
void setcursortype(uint8_t cursor_type) __z88dk_fastcall
{
	switch (cursor_type) {
		case NOCURSOR:
			ADDR_POINTER_BYTE(CSRSW) = 0;
			break;
		case NORMALCURSOR:
			ADDR_POINTER_BYTE(CSRSW) = 1;
			ADDR_POINTER_BYTE(CSTYLE) = 1;
			break;
		case SOLIDCURSOR:
			ADDR_POINTER_BYTE(CSRSW) = 1;
			ADDR_POINTER_BYTE(CSTYLE) = 0;
			break;
	}
}
