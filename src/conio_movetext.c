#include "conio.h"
#include "conio_aux.h"


extern uint8_t *heap_top;

/**
 * movetext
 * Copies the content of a text rectangle on the screen defined by the
 * left and top arguments, which describe the upper-left corner,
 * and by the right and bottom arguments, which describe the lower-right
 * corner, to another rectangle of equal dimensions. The upper-left
 * corner of the new rectangle is specified by the dst_left and dst_top
 * arguments. All coordinates are absolute screen coordinates; they are not
 * relative to the window. Rectangles occupying the same area are moved
 * accordingly. The movetext function uses direct video output.
 * 
 * @return	The movetext function returns a non-zero value if the operation
 * 			is successful. If an error occurs, such as accessing outside
 * 			the screen, it returns a value of 0.
 */
uint8_t movetext(uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, uint8_t dst_left, uint8_t dst_top)
{
	uint8_t dst_right = dst_left + (right-left);
	uint8_t dst_bottom = dst_top + (bottom-top);
	gettext(left, top, right, bottom, heap_top);
	puttext(dst_left, dst_top, dst_right, dst_bottom, heap_top);
	return 1;
}
