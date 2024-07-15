#include <string.h>
#include "conio.h"
#include "conio_aux.h"


extern uint8_t *heap_top;
extern const char frameChars[11];

/**
 * drawFrame
 * The function draw a rectangled frame at a given position.
 * The characters used to draw the frame is system dependent. Drawing a frame that 
 * is partially off screen leads to undefined behaviour.
 */
void drawFrame(uint8_t left, uint8_t top, uint8_t right, uint8_t bottom)
{
	uint8_t width = right - left + 1;

	memset(heap_top, frameChars[FRAME_HORIZ_UP], width);
	heap_top[0] = frameChars[FRAME_UP_LEFT];
	heap_top[width-1] = frameChars[FRAME_UP_RIGHT];
	putlinexy(left, top, width, heap_top);

	memset(heap_top, frameChars[FRAME_HORIZ_DOWN], width);
	heap_top[0] = frameChars[FRAME_DOWN_LEFT];
	heap_top[width-1] = frameChars[FRAME_DOWN_RIGHT];
	putlinexy(left, bottom, width, heap_top);

	memset(heap_top, frameChars[FRAME_FILL], width);
	heap_top[0] = frameChars[FRAME_VERT_LEFT];
	heap_top[width-1] = frameChars[FRAME_VERT_RIGHT];
	for (uint8_t i=top+1; i<bottom; i++) {
		putlinexy(left, i, width, heap_top);
	}
}
