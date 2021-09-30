#include "msx_const.h"
#include "conio.h"

#define ADR_BLINK 0x800


extern text_info _current_text_info;


void _applyColors();
void _setRegVDP(uint16_t portValue) __z88dk_fastcall;
void _fillVRAM(uint16_t vram, uint16_t len, uint8_t value);
uint8_t getByteVRAM(uint16_t vram) __z88dk_fastcall;
void setByteVRAM(uint16_t vram, uint8_t value);
void _copyVRAMtoRAM(uint16_t vram, uint16_t memory, uint16_t size);
void _copyRAMtoVRAM(uint16_t memory, uint16_t vram, uint16_t size);
void _setBlinkBit();