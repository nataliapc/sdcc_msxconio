#include "conio.h"
#include "conio_aux.h"


/**
 * putlinexy
 * Prints the content of a buffer directly on the screen at the specified position.
 */
void putlinexy(uint8_t x, uint8_t y, uint8_t length, void *source)
{
	uint16_t pos = _current_text_info.vramCharMap + (y - 1) * _current_text_info.screenwidth + x - 1;
	_copyRAMtoVRAM((uint16_t)source, pos, length);
}
