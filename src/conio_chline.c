#include <string.h>
#include "conio.h"


extern uint8_t *heap_top;
extern const char frameChars[11];

/**
 * chline
 * The function outputs a horizontal line with the given length starting at the 
 * current cursor position.
 * The character used to draw the horizontal line is system dependent. If available, 
 * a line drawing character is used. Drawing a line that is partially off screen 
 * leads to undefined behaviour.
 */
void chline(uint8_t length)
{
	memset(heap_top, frameChars[FRAME_HORIZONTAL], length);
	putlinexy(wherex(), wherey(), length, heap_top);
}
