#include "msx_const.h"
#include "conio.h"


/**
 * Obtiene la coordenada y de la posición del cursor actual (dentro de la 
 * ventana de texto en uso).
 * 
 * @return	La función wherey retorna un número entero entre 0 y menor al 
 * 			número de filas en el modo de texto en uso.
 */
int wherey() __naked
{
	__asm
		ld  a,(#CSRY)
		dec a
		ld  l,a
		ret
	__endasm;
}
