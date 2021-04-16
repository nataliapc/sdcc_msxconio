#include "msx_const.h"
#include "conio.h"


/**
 * Obtiene la coordenada y de la posición del cursor actual (dentro de la 
 * ventana de texto en uso).
 * 
 * @return	La función wherey retorna un número entero entre 1 y el número 
 * 			de filas en el modo de texto en uso.
 */
uint8_t wherey() __naked
{
	__asm
		ld  a,(#CSRY)
		ld  l,a
		ret
	__endasm;
}
