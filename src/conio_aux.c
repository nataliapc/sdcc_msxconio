#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"
#include <stdio.h>


//=============================================
void _applyColors() __naked
{
	__asm
		ld hl, #FORCLR		// Read ForeColor
		ld a, (hl)
		add a				// << 4 bits
		add a
		add a
		add a
		inc hl
		or (hl)	; #BAKCLR	// Or the BackColor
		
		ld  l, a			// Call to change RegVDP#7
		ld  h, #7
		jp  __setRegVDP
	__endasm;
}


//=============================================
void _setRegVDP(uint16_t portValue) __naked __z88dk_fastcall
{
	__asm
		ld  b, l		// Value
		ld  c, h		// Port
		ld ix, #WRTVDP
		JP_BIOSCALL
	__endasm;
}


//=============================================
// FILVRM: Fill VRAM with value
// [Input: A-Data byte|BC-Length|HL-VRAM address]
// [Changes: AF,BC]
void _fillVRAM(uint16_t vram, uint16_t len, uint8_t value) __naked
{
	__asm
		ld  ix,#2
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)
		ld  c, 2(ix)
		ld  b, 3(ix)
		ld  a, 4(ix)

		ld ix, #FILVRM
		JP_BIOSCALL
	__endasm;
}


//=============================================
uint8_t getByteVRAM(uint16_t vram) __naked __z88dk_fastcall
{
	__asm
		ld  ix,#2
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)

		ld  ix, #SETRD
		BIOSCALL

		in  a, (0x98)
		ld  l, a
		ret
	__endasm;
}


//=============================================
void setByteVRAM(uint16_t vram, uint8_t value) __naked
{
	__asm
		ld  ix,#2
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)
		ld  b, 2(ix)

		ld  ix, #SETWRT
		BIOSCALL

		ld  a,b
		out (0x98), a
		ret
	__endasm;
}


//=============================================
// LDIRMV: Block transfer to memory from VRAM
// [Input: BC-Length|DE-Start memory address|HL-VRAM address]
// [Changes: ALL]
void _copyVRAMtoRAM(uint16_t vram, uint16_t memory, uint16_t size) __naked
{
	__asm
		ld  ix,#2
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)
		ld  e, 2(ix)
		ld  d, 3(ix)
		ld  c, 4(ix)
		ld  b, 5(ix)

		ld  ix, #SETRD
		BIOSCALL

		di
		ex  de,hl
		ld  a,b
		ld  b,c
		ld  c,#0x98
.loopVR$:
		inir
		dec a
		jp  pe,.loopVR$
		ei
		ret
	__endasm;
}


//=============================================
// LDIRVM: Block transfer to VRAM from memory
// [Input: BC-Length|DE-VRAM address|HL-Start memory address]
// [Changes: ALL]
void _copyRAMtoVRAM(uint16_t memory, uint16_t vram, uint16_t size) __naked
{
	__asm
		ld  ix,#2
		add ix,sp
		ld  e, 0(ix)
		ld  d, 1(ix)
		ld  l, 2(ix)
		ld  h, 3(ix)
		ld  c, 4(ix)
		ld  b, 5(ix)

		ld  ix, #SETWRT
		BIOSCALL

		di
		ex  de,hl
		ld  a,b
		ld  b,c
		ld  c,#0x98
.loopRV$:
		otir
		dec a
		jp  pe,.loopRV$
		ei
		ret
	__endasm;
}


//=============================================
void _setBlinkBit()
{
	if ((_current_text_info.attribute & 0xff00) == 0) return;
	uint16_t pos = (ADDR_POINTER_BYTE(CSRY)-1) * _current_text_info.screenwidth + (ADDR_POINTER_BYTE(CSRX)-1);
	uint8_t bit = 0x80 >> (pos % 8);
	pos /= 8;
	pos += ADR_BLINK;
	setByteVRAM(pos, getByteVRAM(pos) | bit);
}


