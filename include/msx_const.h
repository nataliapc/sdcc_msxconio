/*
#####################################################################
	 MSX Constants & structs
#####################################################################
*/
#ifndef  __MSX_CONST_H__
#define  __MSX_CONST_H__


// ========================================================
// Tools
#define DOSCALL  	call 5
#define BIOSCALL 	ld iy,(#EXPTBL-1) \
                	call CALSLT

#define ADDR_POINTER_BYTE(X)	(*((uint8_t*)X))
#define ADDR_POINTER_WORD(X)	(*((uint16_t*)X))


// ========================================================
// MSX I/O Ports
__sfr __at (0x98) IO_VDP1;
__sfr __at (0x99) IO_VDP2;


// ========================================================
// MSX BIOS
// http://map.grauw.nl/resources/msxbios.php
//
#define CALSLT 	0x01c		// Executes inter-slot call [Input: IY-High byte with slot ID | IX-The address that will be called]
#define WRTVDP	0x047		// Write data in the VDP-register [Input: B-Data to write | C-Register] [Changes: AF,BC]
#define CHGCLR	0x062		// Changes the screen colors [Input: Foreground color in FORCLR | Background color in BAKCLR | Border color in BDRCLR]
#define INITXT	0x06c		// Switches to SCREEN 0 (text screen with 40×24 characters)
#define POSIT	0x0c6		// Moves cursor to the specified position [Input: H-Y pos | L-X pos]


// ========================================================
// MSX-DOS 1.x BIOS
// http://map.grauw.nl/resources/dos2_functioncalls.php
//
#define TERM0   0x00		// Program terminate			CPM MSX1
#define CONIN   0x01		// Console input				CPM MSX1
#define CONOUT  0x02		// Console output				CPM MSX1
#define INNOE   0x08		// Console input w/o echo		    MSX1
#define CONST   0x0B		// Console status				CPM MSX1

#define FOPEN   0x0F		// Open file (FCB)				CPM MSX1
#define FCLOSE  0x10		// Close file (FCB)				CPM MSX1
#define FDELETE 0x13		// Delete file (FCB)			CPM MSX1
#define RDSEQ   0x14		// Sequential read (FCB)		CPM MSX1
#define WRSEQ   0x15		// Sequential write FCB)		CPM MSX1
#define FMAKE   0x16		// Create file (FCB)			CPM MSX1

#define CURDRV  0x19		// Get current drive			CPM MSX1
#define SETDTA  0x1A		// Set disk transfer address	CPM MSX1

#define RDRND   0x21		// Random read (FCB)			CPM MSX1
#define WRRND   0x22		// Random write (FCB)			CPM MSX1
#define FSIZE   0x23		// Get file size (FCB)			CPM MSX1
#define WRBLK   0x26		// Random block read (FCB)		    MSX1
#define RDBLK   0x27		// Random block write (FCB)		    MSX1


// ========================================================
// MSX/MSX2 system constants
// http://map.grauw.nl/resources/msxsystemvars.php
// https://www.msx.org/wiki/System_variables_and_work_area
//
#define LINL40		0xf3ae	// (BYTE) Width for SCREEN 0 (default 37)
#define LINLEN		0xf3B0	// (BYTE) Current screen width per line
#define CRTCNT		0xf3B1	// (BYTE) Number of lines of current screen (default 24)
#define CSRY		0xf3dc	// (BYTE) Y-coordinate of text cursor
#define CSRX		0xf3dd	// (BYTE) X-coordinate of text cursor
#define FORCLR		0xf3e9	// (BYTE) Foreground colour
#define BAKCLR		0xf3eA	// (BYTE) Background colour
#define PUTPNT		0xf3f8	// (WORD) Address in the keyboard buffer where a character will be written
#define GETPNT		0xf3fa	// (WORD) Address in the keyboard buffer where the next character is read
#define CSRSW		0xfca9	// (BYTE) Cursor display switch (0:hidden | 1:visible)
#define CSTYLE		0xfcaa	// (BYTE) Cursor style (0:full cursor | other:halve cursor)
#define EXPTBL		0xfcc1	// (BYTE) BIOS slot


// ========================================================
// MSX character codes and compatible sentences VT-52
// https://www.msx.org/wiki/MSX_Characters_and_Control_Codes
//
#define  VT_BEEP		"\x07"		// A beep sound
#define  VT_UP			"\x1E"		//27,"A"	; Cursor up
#define  VT_DOWN		"\x1F"		//27,"B"	; Cursor down
#define  VT_RIGHT		"\x1C"		//27,"C"	; Cursor right
#define  VT_LEFT		"\x1D"		//27,"D"	; Cursor left
#define  VT_CLRSCR		"\x0C"		//27,"E"	; Clear screen:	Clears the screen and moves the cursor to home
#define  VT_HOME		"\x0B"		//27,"H"	; Cursor home:	Move cursor to the upper left corner.
#define  VT_CLREOS		"\x1B""J"	// Clear to end of screen:	Clear screen from cursor onwards.
#define  VT_CLREOL		"\x1B""K"	// Clear to end of line:	Deletes the line to the right of the cursor.
#define  VT_INSLINE		"\x1B""L"	// Insert line:	Insert a line.
#define  VT_DELLINE		"\x1B""M"	// Delete line:	Remove line.
#define  VT_CLLINE		"\x1B""l"	// Deletes the full line at the cursor
#define  VT_GOTOXY		"\x1B""Y"	// Set cursor position [rc]:	Move cursor to position [r+32]ow,[c+32]olumn encoded as single characters.
#define  VT_CURFULL		"\x1B""x4"	// Cursor to full size
#define  VT_CURHIDE		"\x1B""x5"	// Removes the cursor
#define  VT_CURHALF		"\x1B""y4"	// Cursor to half size
#define  VT_CURSHOW		"\x1B""y5"	// Shows the cursor


#endif //__MSX_CONST_H__
