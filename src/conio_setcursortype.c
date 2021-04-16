#include "msx_const.h"
#include "conio.h"


/**
 * Selecciona la apriencia del cursor entre tres tipos. El argumento 
 * tipo_cursor indica el tipo de cursor a seleccionar según éstos:
 *     NOCURSOR     Desactiva el cursor
 *     NORMALCURSOR Cursor normal: el carácter de subrayado
 *     SOLIDCURSOR  Cursor es un cuadrado relleno
 */
void setcursortype(int cursor_type)
{
	switch (cursor_type) {
		case NOCURSOR:
			ADDR_POINTER_BYTE(CSRSW) = 0;
			break;
		case NORMALCURSOR:
			ADDR_POINTER_BYTE(CSRSW) = 1;
			ADDR_POINTER_BYTE(CSTYLE) = 1;
			break;
		case SOLIDCURSOR:
			ADDR_POINTER_BYTE(CSRSW) = 1;
			ADDR_POINTER_BYTE(CSTYLE) = 0;
			break;
	}
}
