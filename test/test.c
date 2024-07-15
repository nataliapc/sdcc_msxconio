#include "conio.h"
#include "heap.h"
#include <stdio.h>

extern text_info _current_text_info;	// Struct with current text mode info.


int main(char **argv, int argc)
{
	char buf[40*24];

	textmode(BW80);
	textattr(0x00f4);
	while (kbhit()) getch();

	clrscr();
	drawFrame(1,1, 80,11);
	drawFrame(1,12, 40,23);
	drawFrame(41,12, 80,23);
	getch();

	cputs("## clrscr()\n");
	cputs("##############################");
	clreol();
	cputs("## clreol()\n");
	cputs("## cputs()\n");
	printf("## inport(0xc0) = 0x%02X\n", inportb(0xc0));
	printf("## getch() = '%c'\n", getch());
	printf("## getche() = '%c'\n", getche());

	gotoxy(1,1);
	cputs("## gotoxy()\n");
	insline(); getch();
	cputs("## insline()\n");
	delline(); getch();
	cputs("## delline()\n");

	gotoxy(10,10);
	int x = wherex(), y = wherey();
	putch('1\n');
	printf("gotoxy %u,%u", x, y);
	gotoxy(x, y);
	cputs("2\n");

	setcursortype(NOCURSOR);
	cputs("## setcursortype(NOCURSOR)\n");
	getch();
	setcursortype(NORMALCURSOR);
	cputs("## setcursortype(NORMALCURSOR)\n");
	getch();
	setcursortype(SOLIDCURSOR);
	cputs("## setcursortype(SOLIDCURSOR)\n");
	getch();

	chline(40);
	cvline(10);
	getch();
	gettext(1, 1, 40, 24, &buf);
	puttext(41, 1, 80, 24, &buf);

	printf("attribute: 0x%04x\n", _current_text_info.attribute);

	textcolor(BLACK);
	cputs("## textcolor(BLACK)\n");
	textattr(_current_text_info.attribute);
	getch();

	textbackground(WHITE);
	cputs("## textbackground(WHITE)\n");
	getch();

//gotoxy(1,1);
	textattr(0x1af1);
	cputs("## textattr(0x1af1)\n");
	textblink(wherex(), wherey()-1, 40, true);
	getch();
	printf(" printf: hola mundo \n");
	textblink(wherex(), wherey()-2, 40, false);
	getch();
	cprintf(" cprintf: hola mundo \n");
	getch();

	textattr(_current_text_info.normattr);
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
