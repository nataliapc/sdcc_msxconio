#include "conio.h"
#include "conio_aux.h"


/**
 * Saves the content of a text rectangle on the screen defined by the
 * left and top arguments, which describe the upper-left corner,
 * and by the right and bottom arguments, which describe the lower-right
 * corner, into the memory area pointed to by the destination argument. All
 * coordinates are absolute screen coordinates; they are not relative to the
 * window. The upper-left corner is (1,1). The gettext function reads the
 * content in this rectangle into memory sequentially from left to
 * right and from top to bottom. The space required for a rectangle w
 * columns wide and h rows high is defined as:
 *
 * bytes = (h rows) x (w columns)
 * 
 * @return	Returns 1 if the operation is successful. If there is an error, such as
 *			accessing outside the screen, it returns a value of 0.
 */
uint8_t gettext(uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, void *target)
{
	uint16_t pos = _current_text_info.vramCharMap + (top-1) * _current_text_info.screenwidth + (left-1);
	uint16_t aux = (uint16_t)target;
	uint16_t width = right - left + 1;

	for (uint8_t i=top; i<=bottom; i++) {
		_copyVRAMtoRAM(pos, aux, width);
		pos += _current_text_info.screenwidth;
		aux += width;
	}
	return 1;
}
