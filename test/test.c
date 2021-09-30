#include "msx_const.h"
#include "conio.h"
#include "heap.h"
#include <stdio.h>

extern text_info _current_text_info;	// Struct with current text mode info.


int main(char **argv, int argc)
{
	textmode(BW80);

	clrscr();
	cputs("## clrscr()\r\n");
	cputs("##############################\r");
	clreol();
	cputs("## clreol()\r\n");
	cputs("## cputs()\r\n");
	printf("## inport(0xc0) = 0x%02X\n", inportb(0xc0));
	printf("## getch() = '%c'\n", getch());
	printf("## getche() = '%c'\n", getche());

	gotoxy(1,1);
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

	char *buf = malloc(40*24);
	gettext(1, 1, 40, 24, buf);
	puttext(41, 1, 80, 24, buf);
	free(40*24);

	printf("attribute: 0x%04x\n", _current_text_info.attribute);

	textcolor(BLACK);
	cputs("## textcolor(BLACK)\r\n");
	textattr(_current_text_info.attribute);
	getch();

	textbackground(WHITE);
	cputs("## textbackground(WHITE)\r\n");
	textattr(_current_text_info.attribute);
	getch();

	textattr(0x1af1);
	cputs("## textattr(0x1af1)\r\n");
	textattr(_current_text_info.attribute);
	printf(" hola mundo ");
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
