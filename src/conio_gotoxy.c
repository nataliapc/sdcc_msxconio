#include "msx_const.h"
#include "conio.h"


/**
 * Mueve el cursor de la ventana de texto a la posición según las coordenadas 
 * especificadas por los argumentos x e y. Si las coordenadas no son válidas 
 * entonces la llamda a la función gotoxy es ignorada.
 */
void gotoxy(uint8_t x, uint8_t y)
{
	if (x<1 || y<1) return;

	cputs(VT_GOTOXY);
	putch(31+x);
	putch(31+y);
}
