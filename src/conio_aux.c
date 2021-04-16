#include "msx_const.h"
#include "conio.h"



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
