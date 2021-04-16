#include "msx_const.h"
#include "conio.h"


/**
 * Muestra la cadena, que finaliza con el carácter nulo, apuntada por el 
 * argumento *cadena en la ventana de texto actual. Esta función es similar a 
 * la función puts, pero con dos excepciones: la función cputs no convertirá 
 * los caracteres de nueva línea (\n) en la pareja de caracteres de retorno de 
 * línea/nueva línea (\r\n) tampoco añadirá el carácter de nueva línea al 
 * final del texto.
 * 
 * Esto se realiza mediante una escritura directa a la memoria de la pantalla.
 * 
 * @return	Retorna el último carácter mostrado en pantalla.
 */
int cputs(const char *str)
{
	int ret = 0;
	while (*str != 0) {
		ret = putch(*str);
		str++;
	}
	return ret;
}
