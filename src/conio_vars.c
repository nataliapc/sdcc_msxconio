#include "conio.h"



// Variables and struct with current text mode info
uint8_t _lastMode;
uint8_t _currentMode;
text_info _current_text_info;

// Graphical chars to build frames
const char frameChars[11] = {
	'\x18',		// Up left
	'\x19',		// Up right
	'\x1a',		// Down left
	'\x1b',		// Down right
	'\x17',		// Horizontal up
	'\x17',		// Horizontal down
	'\x16',		// Vertical left
	'\x16',		// Vertical right
	'\x17',		// Horizontal line
	'\x16',		// Vertical line
	' '			// Fill character
};
