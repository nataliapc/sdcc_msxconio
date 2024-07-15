#include <string.h>
#include "conio.h"


extern uint8_t *heap_top;
extern const char frameChars[11];

/**
 * cvline
 * The function outputs a vertical line with the given length starting at the 
 * current cursor position.
 * The character used to draw the vertical line is system dependent. If available, 
 * a line drawing character is used. Drawing a line that is partially off screen 
 * leads to undefined behaviour.
 */
void cvline(uint8_t length)
{
	memset(heap_top, frameChars[FRAME_VERTICAL], length);
	puttext(wherex(), wherey(), wherex(), wherey() + length - 1, heap_top);
}
