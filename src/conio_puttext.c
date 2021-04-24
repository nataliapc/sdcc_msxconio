#include "msx_const.h"
#include "conio.h"

#include <stdio.h>


extern text_info _current_text_info;
void _copyRAMtoVRAM(uint16_t memory, uint16_t vram, uint16_t size);

/**
 * Imprime el contenido en un rectángulo de texto en pantalla definido por los 
 * argumentos izquierda y superior, que describen la esquina superior 
 * izquierda y por los argumentos derecha e inferior, que describen la esquina 
 * inferior derecha, en el área de memoria apuntada por el argumento origen. 
 * Todas las coordenadas son coordenadas absolutas de pantalla; no son 
 * relativas a la ventana. La esquina superior izquierda es (1,1). La función 
 * puttext coloca el contenido de este rectángulo en memoria secuencialmente 
 * de izquierda a derecha y de arriba a abajo. Cada posición en pantalla 
 * contiene 2 bytes de memoria. El primer byte es el carácter en la celda y el 
 * segundo es el atributo de vídeo de la celda. El espacio requerido para un 
 * rectángulo b columnas anchas y h filas altas está definida como:
 *
 * bytes = (h filas) x (w anchas) x 2.
 *
 * La función puttext usa la salida directa de vídeo.
 *
 * @return	La función puttext retorna un valor distinto a 0, si la operación 
 * 			tiene éxito. Si ocurre un error, como es el caso de acceder fuera 
 * 			de la pantalla, entonces retorna el valor de 0.
 */
uint8_t puttext(uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, void *source)
{
	uint16_t pos = _current_text_info.vramCharMap + (top-1) * _current_text_info.screenwidth + left - 1;
	uint16_t aux = (uint16_t)source;
	uint16_t width = right - left + 1;

	for (uint8_t i=top; i<=bottom; i++) {
		_copyRAMtoVRAM(aux, pos, width);
		aux += width;
		pos += _current_text_info.screenwidth;
	}
	return 1;
}
