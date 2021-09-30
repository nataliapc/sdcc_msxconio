#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
 * Esta función despeja la ventana de texto actual y coloca el cursor en la 
 * esquina superior izquierda: posición (0,0).
 *
 * Initial screen position in original conio library is (1,1).
 */
void clrscr()
{
	_fillVRAM(_current_text_info.vramCharMap, 0x800, 32);
	_fillVRAM(ADR_BLINK, 0xf0, 0);
}
