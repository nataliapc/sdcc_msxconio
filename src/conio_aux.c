#include "msx_const.h"
#include "conio.h"



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
		
		ld  b, a			// Call to change RegVDP#7
		ld  c, #7
		ld ix, #WRTVDP
		BIOSCALL
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
		pop af
		pop hl
		pop de
		pop bc
		push bc
		push de
		push hl
		push af

		ld ix, #LDIRMV
		BIOSCALL
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
		pop af
		pop hl
		pop de
		pop bc
		push bc
		push de
		push hl
		push af

		ld ix, #LDIRVM
		BIOSCALL
		ret
	__endasm;
}
