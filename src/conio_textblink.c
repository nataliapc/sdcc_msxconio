#include "conio.h"
#include "conio_aux.h"


/**
 * textblink
 * Activates or deactivates text blinking in a given region.
 */
void textblink(uint8_t x, uint8_t y, uint16_t length, bool enabled)
{
	uint16_t pos = ((uint16_t)y - 1) * ((uint16_t)_current_text_info.screenwidth) + ((uint16_t)x - 1);
	uint16_t address = ADR_BLINK + pos / 8;
	uint8_t bit = 0x80 >> (pos % 8);
	uint8_t value;

	value = getByteVRAM(address);
	while (length) {
		if (bit == 0x80 && length > 8) {
			_fillVRAM(address, length/8, enabled ? 0xff : 0x00);
			address += length/8;
			length %= 8;
			value = getByteVRAM(address);
		} else {
			if (enabled) {
				value |= bit;
			} else {
				value &= ~bit;
			}
			bit >>= 1;
			if (bit == 0) {
				setByteVRAM(address, value);
				address++;
				bit = 0x80;
				value = getByteVRAM(address);
			}
			length--;
		}
	}
	setByteVRAM(address, value);
}
