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
void _setRegVDP(uint16_t portValue) __naked __sdcccall(1)
{
	__asm
		push ix
		ld  b, l		// Value
		ld  c, h		// Port
		ld ix, #WRTVDP
		BIOSCALL
		pop ix
		ret
	__endasm;
}


//=============================================
// FILVRM: Fill VRAM with value
// [Input: A-Data byte|BC-Length|HL-VRAM address]
// [Changes: AF,BC]
void _fillVRAM(uint16_t vram, uint16_t len, uint8_t value) __naked __sdcccall(0)
{
	__asm
		push ix
		ld  ix,#4
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)
		ld  c, 2(ix)
		ld  b, 3(ix)
		ld  a, 4(ix)

		ld ix, #FILVRM
		BIOSCALL
		pop ix
		ret
	__endasm;
}


//=============================================
uint8_t getByteVRAM(uint16_t vram) __naked __sdcccall(1)
{
	__asm
		push ix				; HL = Param vram
		ld  ix, #RDVRM
		BIOSCALL
		pop ix
		ret					; Returns A
	__endasm;
}


//=============================================
void setByteVRAM(uint16_t vram, uint8_t value) __naked __sdcccall(0)
{
	__asm
		push ix
		ld  ix,#4
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)
		ld  a, 2(ix)
		ld  ix, #WRTVRM
		BIOSCALL
		pop ix
		ret
	__endasm;
}


//=============================================
// LDIRMV: Block transfer to memory from VRAM
// [Input: BC-Length|DE-Start memory address|HL-VRAM address]
// [Changes: ALL]
void _copyVRAMtoRAM(uint16_t vram, uint16_t memory, uint16_t size) __naked __sdcccall(0)
{
	__asm
		push ix
		ld  ix,#4
		add ix,sp
		ld  l, 0(ix)
		ld  h, 1(ix)
		ld  e, 2(ix)
		ld  d, 3(ix)
		ld  c, 4(ix)
		ld  b, 5(ix)

		ld  ix, #SETRD
		BIOSCALL
		pop ix

		ex  de,hl
		ld  a,b
		ld  b,c
		ld  c,#0x98
.loopVR$:
		inir
		dec a
		jp  pe,.loopVR$
		ret
	__endasm;
}


//=============================================
// LDIRVM: Block transfer to VRAM from memory
// [Input: BC-Length|DE-VRAM address|HL-Start memory address]
// [Changes: ALL]
void _copyRAMtoVRAM(uint16_t memory, uint16_t vram, uint16_t size) __naked __sdcccall(0)
{
	__asm
		push ix
		ld  ix,#4
		add ix,sp
		ld  e, 0(ix)
		ld  d, 1(ix)
		ld  l, 2(ix)
		ld  h, 3(ix)
		ld  c, 4(ix)
		ld  b, 5(ix)

		ld  ix, #SETWRT
		BIOSCALL
		pop ix

		ex  de,hl
		ld  a,b
		ld  b,c
		ld  c,#0x98
.loopRV$:
		otir
		dec a
		jp  pe,.loopRV$
		ret
	__endasm;
}
