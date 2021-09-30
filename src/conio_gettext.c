#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
 * Guarda el contenido en un rectángulo de texto en pantalla definido por los 
 * argumentos izquierda y superior, que describen la esquina superior izquierda
 * y por los argumentos derecha e inferior, que describen la esquina inferior 
 * derecha, en el área de memoria apuntada por el argumento destino. Todas las 
 * coordenadas son coordenadas absolutas de pantalla; no son relativas a la 
 * ventana. La esquina superior izquierda es (1,1). La función gettext lee el 
 * contenido en este rectángulo en memoria secuencialmente de izquierda a 
 * derecha y de arriba a abajo. Cada posición en pantalla necesita 2 bytes de 
 * memoria. El primer byte es el carácter en la celda y el segundo es el 
 * atributo de vídeo de la celda. El espacio requerido para un rectángulo b 
 * columnas anchas y h filas altas está definida como:
 *
 * bytes = (h filas) x (w anchas) x 2.
 * 
 * @return	Retorna 1 si la operación tiene éxito. Si hay un error, como es el 
 *			caso de acceder fuera de la pantalla, retorna el valor de 0.
 */
uint8_t gettext(uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, void *target)
{
	uint16_t pos = _current_text_info.vramCharMap + (top-1) * _current_text_info.screenwidth + (left-1);
	uint16_t aux = (uint16_t)target;
	uint16_t width = right - left + 1;

	for (uint8_t i=top; i<=bottom; i++) {
		_copyVRAMtoRAM(pos, aux, width);
		pos += _current_text_info.screenwidth;
		aux += width;
	}
	return 1;
}
