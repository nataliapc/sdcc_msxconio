#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


extern uint8_t _currentMode;
extern uint8_t _lastMode;

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
			_current_text_info.currmode = mode;
			_current_text_info.screenwidth = 40;
			_current_text_info.screenheight = 24;
			_current_text_info.vramCharMap = 0x0000;
			_current_text_info.winleft = 1;
			_current_text_info.wintop = 1;
			_current_text_info.winright = 40;
			_current_text_info.winbottom = 24;
			break;

		case _ORIGMODE:
		case BW80:
			_current_text_info.currmode = mode;
			_current_text_info.screenwidth = 80;
			_current_text_info.screenheight = 24;
			_current_text_info.vramCharMap = 0x0000;
			_current_text_info.winleft = 1;
			_current_text_info.wintop = 1;
			_current_text_info.winright = 80;
			_current_text_info.winbottom = 24;
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
		ld ix,#INITXT
		BIOSCALL
	__endasm;
}
