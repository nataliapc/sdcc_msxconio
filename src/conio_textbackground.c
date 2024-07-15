#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
 * This function selects the background color specified by the color argument.
 * This function only works with those functions that send output data in text
 * mode directly to the screen. The color argument is an integer between 0 and 7;
 * symbolic constants defined in conio.h can also be used instead of integers.
 * The textattr function does not affect any of the characters currently on the
 * screen, but it does affect those displayed by functions that use video directly
 * for text mode output after calling the textattr function.
 *
 * There are several symbolic color constants available for use.
 */
void textbackground(uint8_t color) __z88dk_fastcall
{
	ADDR_POINTER_BYTE(BAKCLR) = color;

	_current_text_info.attribute &= 0xf0;
	_current_text_info.attribute |= color;

	_applyColors();
}
