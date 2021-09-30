#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


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
 *     B b b b f f f f
 *   En el argumento atributo de 8 bits:
 *     ffff es el color de primer plano de 4 bits (0-15).
 *     bbb es el color de fondo de 3 bits (0-7).
 *     B es el bit de encendido de parpadeo.
 *
 * MSX
 *   Attributo de 16 bits:
 *     F E D C B A 9 8 7 6 5 4 3 2 1 0
 *     F F F F B B B B f f f f b b b b
 *   Valores:
 *     ffff foreground color (0-15)
 *     bbbb background color (0-15)
 *     FFFF foreground blink color (0-15)
 *     BBBB background blink color (0-15)
 *
 * If FFFF and BBBB are 0 the blink mode is disabled.
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
void textattr(uint16_t attribute) __z88dk_fastcall
{
	_current_text_info.attribute = attribute;
	
	ADDR_POINTER_BYTE(FORCLR) = ((uint8_t)attribute) >> 4;
	ADDR_POINTER_BYTE(BAKCLR) = ((uint8_t)attribute) & 0x0f;
	
	attribute >>= 8;
	if (attribute==0) {
		_setRegVDP(0x0c00);
		_setRegVDP(0x0d00);
	} else {
		_setRegVDP(0x0c00 | attribute);
		_setRegVDP(0x0d10);
	}

	_applyColors();		// Apply color changes
}
