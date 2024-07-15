#include "conio.h"
#include "conio_aux.h"


/**
 * window
 * Defines a text window on the screen specified by the left and top arguments,
 * which describe the upper left corner, and by the right and bottom arguments,
 * which describe the lower right corner. The minimum size of the text window
 * is one column by one row. The default window is the full screen with the
 * upper left corner being (1,1) and the lower right being (C,R); where C is
 * less than the number of columns and R less than the number of rows according
 * to the text mode in use. The call to the window function will be ignored if
 * any of the arguments are invalid.
 */
void window(int left, int top, int right, int bottom)
{
	_current_text_info.winleft = left;
	_current_text_info.wintop = top;
	_current_text_info.winright = right;
	_current_text_info.winbottom = bottom;
}
