#include "msx_const.h"
#include "conio.h"


/**
 * TODO getche
 * Lee un solo carácter directamente desde el teclado, mostrando tal carácter 
 * en pantalla, directamente a vídeo.
 *
 * @return	La función getche retorna el carácter leído del teclado.
 */
int getche() __naked
{
	__asm
		ld c,#CONIN
		DOSCALL
		ld h, #0x00

		ret
	__endasm;
}
