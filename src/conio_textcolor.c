#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
 * Esta función selecciona el color de texto especificado por el argumento 
 * color. Esta función solamente funciona con aquellas funciones que envían 
 * datos de salida en modo texto directamente a la pantalla. El argumento 
 * color es un número entero entre 0 y 15; también se pueden usar constantes 
 * simbólicas definidas en conio.h en lugar de enteros. La función textcolor 
 * no afecta a ninguno de los caracteres actualmente en pantalla, pero sí 
 * afecta aquéllas mostradas por funciones que usan el vídeo directamente para 
 * la salida en modo texto después de llamar a la función textcolor.
 *
 * Existen varias constantes simbólicas de colores para usar.
 */
void textcolor(uint8_t color) __z88dk_fastcall
{
	ADDR_POINTER_BYTE(FORCLR) = color;

	color <<= 4;
	_current_text_info.attribute &= 0x0f;
	_current_text_info.attribute |= color;

	_applyColors();
}
