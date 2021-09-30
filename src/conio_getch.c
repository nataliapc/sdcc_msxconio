#include "msx_const.h"
#include "conio.h"


/**
 * Lee un solo carácter directamente desde el teclado, sin mostrar tal 
 * carácter en pantalla.
 * 
 * @return	Retorna el carácter leído desde el teclado.
 */
int getch() __naked
{
	__asm
		ld c,#INNOE
		DOSCALL
		ld h, #0x00

		ret
	__endasm;
}
