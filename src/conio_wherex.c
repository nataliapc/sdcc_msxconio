#include "msx_const.h"
#include "conio.h"


/**
 * Obtiene la coordenada x de la posición del cursor actual (dentro de la 
 * ventana de texto en uso).
 * 
 * @return	La función wherex retorna un número entero entre 0 y menor al 
 * 			número de columnas en el modo de texto en uso.
 */
int wherex() __naked
{
	__asm
		ld  a,(#CSRX)
		dec a
		ld  l,a
		ret
	__endasm;
}
