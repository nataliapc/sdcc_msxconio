#include "msx_const.h"
#include "conio.h"


/**
 * TODO kbhit
 * Revisa si una tecla pulsada está disponible. Cualesquier pulsadas 
 * disponibles pueden ser recogidas con las funciones getch o getche.
 * 
 * @return	La función kbhit retorna 0 si no se ha registrado una pulsación 
 * 			de tecla; si hay una disponible, entonces el valor retornado es 
 * 			distinto a cero.
 */
int kbhit(void)
{
	return ADDR_POINTER_WORD(PUTPNT) - ADDR_POINTER_WORD(GETPNT);
}
