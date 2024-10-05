#include <string.h>
#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


extern uint8_t _currentMode;
extern uint8_t _lastMode;

static const text_info _BW40 = {
	1,		// winleft: Left coordinate of the window
	1,		// wintop: Top coordinate of the window
	40,		// winright: Right coordinate of the window
	24,		// winbottom: Bottom coordinate of the window
	0,		// attribute: Current text attributes. See textattr()
	0,		// normattr: Attributes before textmode() was called
	BW40,	// currmode: Mode in use: BW40, BW80, C40, C80, or C4350
	24,		// screenheight: Height of the text screen
	40,		// screenwidth: Width of the text screen
	1,		// curx: X coordinate of the current window
	1, 		// cury: Y coordinate of the current window
	//Only MSX
	false,	// vramBlink: True for text blink enabled
	0x0000,	// vramCharMap: Address at VRAM for chars(tiles) map
	0x0800,	// vramCharPat: Address at VRAM for chars(tiles) patterns
};

static const text_info _BW80 = {
	1,		// winleft: Left coordinate of the window
	1,		// wintop: Top coordinate of the window
	80,		// winright: Right coordinate of the window
	24,		// winbottom: Bottom coordinate of the window
	0,		// attribute: Current text attributes. See textattr()
	0,		// normattr: Attributes before textmode() was called
	BW80,	// currmode: Mode in use: BW40, BW80, C40, C80, or C4350
	24,		// screenheight: Height of the text screen
	80,		// screenwidth: Width of the text screen
	1,		// curx: X coordinate of the current window
	1, 		// cury: Y coordinate of the current window
	//Only MSX
	true,	// vramBlink: True for text blink enabled
	0x0000,	// vramCharMap: Address at VRAM for chars(tiles) map
	0x1000,	// vramCharPat: Address at VRAM for chars(tiles) patterns
};

/**
 * This function selects a text mode specified by the mode argument.
 * This argument can be a symbolic constant of the text_modes enumeration type
 * (in conio.h).
 * 
 * When the textmode function is called, the window in use is reset to the
 * full screen, and the text attributes in use are reset to normal,
 * corresponding to a call to normvideo. Specifying LASTMODE to textmode
 * causes the most recently selected text mode to be selected again.
 * 
 * The textmode function should only be used when the window or screen is
 * in text mode (presumably to change to a different text mode).
 * This is the only context where the textmode function is used. When the
 * screen is in graphics mode, use the restorecrtmode function instead of
 * temporarily exiting to text mode.
 * 
 * There are several symbolic constants to indicate the text modes.
 */
void textmode(int8_t mode) __z88dk_fastcall
{
	if (mode == LASTMODE) {
		mode = _lastMode;
	}

	switch (mode) {
		case BW40:
			memcpy(&_current_text_info, &_BW40, sizeof(text_info));
			break;
		case _ORIGMODE:
		case BW80:
			memcpy(&_current_text_info, &_BW80, sizeof(text_info));
			break;
		default:
			return;
	}
	_currentMode = mode;

	_current_text_info.normattr = ADDR_POINTER_BYTE(BAKCLR) | (ADDR_POINTER_BYTE(FORCLR)<<4);
	_current_text_info.attribute = _current_text_info.normattr;

	ADDR_POINTER_BYTE(LINL40) = _current_text_info.screenwidth;
	ADDR_POINTER_BYTE(CRTCNT) = _current_text_info.screenheight;
	__asm
		BIOSCALL(INITXT)
	__endasm;

	// Clear blink data
	clrblink();
}
