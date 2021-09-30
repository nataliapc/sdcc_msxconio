#include "msx_const.h"
#include "conio.h"


/**
 * Obtiene la coordenada x de la posición del cursor actual (dentro de la 
 * ventana de texto en uso).
 * 
 * @return	La función wherex retorna un número entero entre 1 y el número 
 * 			de columnas en el modo de texto en uso.
 */
uint8_t wherex() __naked
{
	__asm
		ld  a,(#CSRX)
		ld  l,a
		ret
	__endasm;
}
