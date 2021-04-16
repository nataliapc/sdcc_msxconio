#include "msx_const.h"
#include "conio.h"


/**
 * Esta función despeja la ventana de texto actual y coloca el cursor en la 
 * esquina superior izquierda: posición (0,0).
 *
 * Initial screen position in original conio library is (1,1).
 */
void clrscr(void)
{
	cputs(VT_CLRSCR);
}
