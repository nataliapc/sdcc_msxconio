#include "msx_const.h"
#include "conio.h"


/**
 * Inserta una línea vacía en la ventana de texto en la posición del cursor 
 * usando el color de fondo de texto en uso. Todas las líneas debajo de la 
 * vacía son mudadas una línea más abajo, y la línea inferior es mudada fuera 
 * de la ventana.
 */
void insline(void)
{
	cputs(VT_INSLINE);
}
