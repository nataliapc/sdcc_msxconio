#include "msx_const.h"
#include "conio.h"


/**
 * Esta función despeja todos los caracteres desde la posición del cursor 
 * hasta el final de la línea dentro de la ventana de texto actual, sin mover 
 * la posición del cursor.
 */
void clreol(void)
{
	cputs(VT_CLREOL);
}
