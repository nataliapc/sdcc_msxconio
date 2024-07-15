#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
 * This function assigns the foreground and background colors in a single
 * call. (Normally, these attributes are assigned using the functions
 * textcolor and textbackground). The textattr function does not affect any
 * of the characters currently on the screen, but it does affect those
 * displayed by functions that use video directly for text mode output
 * after calling the textattr function.
 * 
 * The color information is encoded in the attribute argument according to
 * this diagram:
 * 
 * Standard
 *   Bits	
 *     7 6 5 4 3 2 1 0
 *     B b b b f f f f
 *   In the 8-bit attribute argument:
 *     ffff is the 4-bit foreground color (0-15).
 *     bbb is the 3-bit background color (0-7).
 *     B is the blink enable bit.
 *
 * MSX
 *   16-bit Attribute:
 *     F E D C B A 9 8 7 6 5 4 3 2 1 0
 *     F F F F B B B B f f f f b b b b
 *   Values:
 *     ffff foreground color (0-15)
 *     bbbb background color (0-15)
 *     FFFF foreground blink color (0-15)
 *     BBBB background blink color (0-15)
 *
 * If FFFF and BBBB are 0 the blink mode is disabled.
 * 
 * If using the symbolic constants defined in conio.h to create text
 * attributes using textattr, keep in mind the following limitations
 * for the selected background color:
 * 
 * Only one of the first eight colors can be chosen for the background.
 * You must shift the selected background color 4 bits to the left so that
 * they are placed in the correct bit positions.
 * There are several symbolic color constants to use.
 */
void textattr(uint16_t attribute) __z88dk_fastcall
{
	_current_text_info.attribute = attribute;
	
	ADDR_POINTER_BYTE(FORCLR) = ((uint8_t)attribute) >> 4;
	ADDR_POINTER_BYTE(BAKCLR) = ((uint8_t)attribute) & 0x0f;

	attribute >>= 8;
	if (attribute==0) {
		_setRegVDP(0x0c00);
		_setRegVDP(0x0d00);
	} else {
		_setRegVDP(0x0c00 | attribute);
		_setRegVDP(0x0d10);
	}

	_applyColors();		// Apply color changes
}
