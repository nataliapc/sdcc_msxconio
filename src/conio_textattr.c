#include "msx_const.h"
#include "conio.h"


/**
 * Esta función asigna los colores de primer plano y de fondo en una sola 
 * llamada. (Normalmente, se asignan estos atributos mediante las funciones 
 * a textcolor y textbackground). La función textattr no afecta cualesquiera 
 * de los caracteres actualmente en pantalla, pero sí afecta aquéllas 
 * mostradas por funciones que usan el vídeo directamente para la salida en 
 * modo texto después de llamar a la función textattr.
 * 
 * La información de los colores está codificado en el argumento atributo según
 * este diagrama:
 * 
 * Estandar
 *   Bits	
 *     7 6 5 4 3 2 1 0
 *     B f f f p p p p
 *   En el argumento atributo de 8 bits:
 *     pppp es el color de primer plano de 4 bits (0-15).
 *     fff es el color de fondo de 3 bits (0-7).
 *     B es el bit de encendido de parpadeo.
 * MSX
 *   Attributo de 9 bits:
 *     8 7 6 5 4 3 2 1 0
 *     B f f f f p p p p
 *   Valores:
 *     pppp color del primer plano (0-15)
 *     ffff color de fondo (0-15)
 *     B bit de encendido de parpadeo.
 *
 * Si el bit del parpadeo está activado, entonces los caracteres parpadean. 
 * Esto se puede lograr añadiendo la constante BLINK al atributo.
 * 
 * Si se usan las constantes simbólicas definidas en conio.h para crear los 
 * atributos de texto usando textattr, ten en cuenta las siguientes 
 * limitaciones para el color de fondo seleccionado:
 * 
 * Sólo se pueden elegir uno de los primeros ocho colores para el fondo.
 * Deberás mudar el color de fondo seleccionado 4 bits a la izquierda para que 
 * estén colocados en las posiciones correctas de los bits.
 * Existen varias constantes simbólicas de colores para usar.
 */
void textattr(uint16_t attribute) __naked __z88dk_fastcall
{
	//TODO apply blink bit
	__asm
		ld a,l				// Change BackColor in System Area
		and #0x0f
		ld (#BAKCLR),a

		ld a,l				// Change ForeColor in System Area
		srl a
		srl a
		srl a
		srl a
		ld (#FORCLR),a
		
		jp __applyColors	// Apply color changes
	__endasm;
}
