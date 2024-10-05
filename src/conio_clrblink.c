#include "conio.h"
#include "conio_aux.h"


/**
 * This function clears fullscreen text blinking.
 */
void clrblink()
{
	if (_current_text_info.vramBlink) {
		_fillVRAM(ADR_BLINK, 240, 0);
	}
}
