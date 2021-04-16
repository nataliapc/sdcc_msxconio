#include "msx_const.h"
#include "conio.h"
#include <stdio.h>



int main(char **argv, int argc)
{
	textmode(BW80);

	clrscr();
	cputs("## clrscr()\r\n");
	cputs("##############################\r");
	clreol();
	cputs("## clreol()\r\n");
	cputs("## cputs()\r\n");
	printf("## inport(0x18) = 0x%02X\n", inportb(0x18));
	printf("## getch() = '%c'\n", getch());
	printf("## getche() = '%c'\n", getche());

	gotoxy(0,0);
	cputs("## gotoxy()\r\n");
	insline(); getch();
	cputs("## insline()\r\n");
	delline(); getch();
	cputs("## delline()\r\n");

	gotoxy(10,10);
	int x = wherex(), y = wherey();
	putch('1');
	printf(" %u,%u", x, y);
	gotoxy(x, y);
	cputs("2\r\n");

	setcursortype(NOCURSOR);
	cputs("## setcursortype(NOCURSOR)\r\n");
	while (!kbhit());
	getch();
	setcursortype(NORMALCURSOR);
	cputs("## setcursortype(NORMALCURSOR)\r\n");
	while (!kbhit());
	getch();
	setcursortype(SOLIDCURSOR);
	cputs("## setcursortype(SOLIDCURSOR)\r\n");
	while (!kbhit());
	getch();

	textcolor(BLACK);
	cputs("## textcolor(BLACK)\r\n");
	getch();

	textbackground(WHITE);
	cputs("## textbackground(WHITE)\r\n");
	getch();

	textattr(0xf1);
	cputs("## textattr(0xf1)\r\n");
	getch();


	return 0;
}


/*
void initScreen(CONFIG *config)
{
	ADDR_POINTER_BYTE(FORCLR) = config->fgColor;
	ADDR_POINTER_BYTE(BAKCLR) = config->bgColor;
	ADDR_POINTER_BYTE(BDRCLR) = config->border;
	ADDR_POINTER_BYTE(LINL40) = config->scrWidth;
	__asm
		BIOSCALL(#INITXT)
	__endasm;
}

void setWriteVDP(uint16_t vramAddr) __naked
{
	vramAddr;
	__asm
		pop  af
		pop  hl				; vramAddr
		push hl
		push af

	setWriteVDP::
		ld   a,l
		di
		out  (0x99),a
		ld   a,h
		and  #0x3f
		or   #0x40
		out  (0x99),a
		ei
		ret
	__endasm;
}

void setReadVDP(uint16_t vramAddr) __naked
{
	vramAddr;
	__asm
		pop  af
		pop  hl				; vramAddr
		push hl
		push af

	setReadVDP::
		ld   a,l
		di
		out  (0x99),a
		ld   a,h
		and  #0x3f
		out  (0x99),a
		ei
		ret
	__endasm;
}
*/