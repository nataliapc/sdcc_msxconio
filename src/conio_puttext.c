#include "conio.h"
#include "conio_aux.h"


/**
 * Prints the content in a text rectangle on the screen defined by the
 * left and top arguments, which describe the upper left corner,
 * and by the right and bottom arguments, which describe the lower
 * right corner, in the memory area pointed to by the source argument.
 * All coordinates are absolute screen coordinates; they are not
 * relative to the window. The upper left corner is (1,1). The
 * puttext function places the contents of this rectangle in memory sequentially
 * from left to right and from top to bottom. The space required for a
 * rectangle w columns wide and h rows high is defined as:
 *
 * bytes = (h rows) x (w columns)
 *
 * The puttext function uses direct video output.
 *
 * @return	The puttext function returns a non-zero value if the operation
 * 			is successful. If an error occurs, such as accessing outside
 * 			the screen, then it returns a value of 0.
 */
uint8_t puttext(uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, void *source)
{
	if (left>right || top>bottom) return 0;
	uint16_t pos = _current_text_info.vramCharMap + (top-1) * _current_text_info.screenwidth + left - 1;
	uint16_t width = right - left + 1;
	uint16_t aux_buff = (uint16_t)source;

	for (uint8_t i=top; i<=bottom; i++) {
		_copyRAMtoVRAM(aux_buff, pos, width);
		aux_buff += width;
		pos += _current_text_info.screenwidth;
	}
	return 1;
}
