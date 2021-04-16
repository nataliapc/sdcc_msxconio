#include "msx_const.h"
#include "conio.h"


/**
 * Borra la línea donde se encuentre el cursor y mueve todas las líneas 
 * inferiores a una línea anterior. La función delline funciona en la ventana 
 * de texto activa.
 */
void delline(void)
{
	cputs(VT_DELLINE);
}
