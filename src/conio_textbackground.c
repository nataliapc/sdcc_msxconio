#include "msx_const.h"
#include "conio.h"

void _applyColors() __naked;


/**
 * Esta función selecciona el color de fondo especificado por el argumento 
 * color. Esta función solamente funciona con aquellas funciones que envían 
 * datos de salida en modo texto directamente a la pantalla. El argumento 
 * color es un número entero entre 0 y 7; también se pueden usar constantes 
 * simbólicas definidas en conio.h en lugar de enteros. La función textattr no 
 * afecta cualesquiera de los caracteres actualmente en pantalla, pero sí 
 * afecta aquéllas mostradas por funciones que usan el vídeo directamente para 
 * la salida en modo texto después de llamar a la función textattr.
 * 
 * Existen varias constantes simbólicas de colores para usar.
 */
void textbackground(uint8_t color) __naked
{
	__asm
		push ix				; Get 'color' in A
		ld ix,#4
		add ix,sp
		ld a,0(ix)
		pop ix

		ld (#BAKCLR),a		; Change BackColor in System Area
		jp __applyColors	; Apply color changes
	__endasm;
}
