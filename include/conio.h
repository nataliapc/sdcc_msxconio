/**
 * ============================================================================
 *  CONIO Library
 *  https://web.archive.org/web/20090225093706/http://c.conclase.net/Borland/funcion.php?fun=inport
 * ============================================================================
 */
#ifndef  __CONIO_H__
#define  __CONIO_H__

#include <stdint.h>
#include <stdbool.h>



// =====================================================================
// Constants, Enums & Structs

/**
 * Constants for {@link setcursortype}
 */
#define NOCURSOR		0
#define NORMALCURSOR	1
#define SOLIDCURSOR		2

/**
 * Constants for {@link gettextinfo}
 */
enum TextModes {
	LASTMODE = -1,	// Selecciona el modo anterior
	BW40 = 0,		// Blanco y negro 40 columnas
	BW80 = 2		// Blanco y negro 80 columnas
};

/**
 * Color constants
 */
enum Color {
	TRANSPARENT = 0,
	BLACK,
	MEDIUM_GREEN,
	LIGHT_GREEN,
	DARK_BLUE,
	LIGHT_BLUE,
	DARK_RED,
	CYAN, 
	MEDIUM_RED,
	LIGHT_RED,
	DARK_YELLOW,
	LIGHT_YELLOW,
	DARK_GREEN,
	MAGENTA, 
	GRAY,
	WHITE,
};

/**
 * Struct for {@link gettextinfo}
 */
typedef struct {
	uint8_t winleft;        // Coordenada izquierda de la ventana
	uint8_t wintop;         // Coordenada superior de la ventana
	uint8_t winright;       // Coordenada derecha de la ventana
	uint8_t winbottom;      // Coordenada inferior de la ventana
	uint8_t attribute;      // Atributo de texto
	uint8_t normattr;       // Atributo normal
	uint8_t currmode;       // Modo en Uso: BW40, BW80, C40, C80, ó C4350
	uint8_t screenheight;   // Altura de la pantalla de texto
	uint8_t screenwidth;    // Anchura de la pantalla de texto
	uint8_t curx;           // Coordenada X de la ventana en uso
	uint8_t cury;           // Coordenada Y de la ventana en uso
} text_info;



// ANCHOR =====================================================================
// Screen functions

/**
 * NOTE gettextinfo
 * Obtiene la información de vídeo del modo texto. Esta información es guardada
 * en una estructura apuntada por el argumento *ti. La estructura text_info se 
 * define segun {@link text_info}
 */
void gettextinfo(text_info *ti);

/**
 * NOTE textmode
 * Esta función selecciona un modo de texto especificado por el argumento modo.
 * Este argumento puede ser una constante simbólica del tipo de enumeración 
 * text_modes (en conio.h).
 * 
 * Cuando se llama a la función textmode, la ventana en uso es reiniciada a la 
 * pantalla completa, y los atributos de texto en uso son reiniciados a normal,
 * correspondiendo a una llamada a normvideo. Especificando LASTMODE a textmode
 * causa el modo de texto más recientemente seleccionado a ser seleccionado de 
 * nuevo.
 * 
 * La función textmode debería usarse solamente cuando la ventana o pantalla es
 * en modo de texto (supuestamente para cambiar a un modo de texto diferente). 
 * Este es el único contexto donde se usa la función textmode. Cuando la 
 * pantalla está en modo gráfico, usa la función restorecrtmode en vez de 
 * salirse temporalmente a modo de texto.
 * 
 * Existen varias constantes simbólicas para indicar los modos de texto.
 */
void textmode(uint8_t mode) __z88dk_fastcall;

/**
 * NOTE setcursortype
 * Selecciona la apriencia del cursor entre tres tipos. El argumento 
 * tipo_cursor indica el tipo de cursor a seleccionar según éstos:
 *     NOCURSOR     Desactiva el cursor
 *     NORMALCURSOR Cursor normal: el carácter de subrayado
 *     SOLIDCURSOR  Cursor es un cuadrado relleno
 */
void setcursortype(uint8_t cursor_type) __z88dk_fastcall;

/**
 * TODO highvideo
 * Selecciona los caracteres con una mayor intensidad mediante activando el 
 * bit de la mayor intensidad del color de primer plano en uso. La función 
 * highvideo no afecta a ninguno de los caracteres actualmente en pantalla, 
 * pero sí afecta aquéllas mostradas por funciones que usan el vídeo 
 * directamente para la salida en modo texto después de llamar a la función 
 * highvideo.
 *
 * Character attribute (Blink)     0800-08EF (090D)
 */
//void highvideo();

/**
 * TODO lowvideo
 * Selecciona los caracteres con una menor intensidad mediante activando el 
 * bit de la menor intensidad del color de primer plano en uso. La función 
 * lowvideo no afecta a ninguno de los caracteres actualmente en pantalla, 
 * pero sí afecta aquéllas mostradas por funciones que usan el vídeo 
 * directamente para la salida en modo texto después de llamar a la función 
 * lowvideo.
 */
//void lowvideo();

/**
 * TODO normvideo
 * Selecciona los caracteres con una intensidad normal mediante seleccionado 
 * del atributo del texto (primer plano y de fondo) al valor que tenía 
 * anteriormente al comienzo del programa. La función normvideo no afecta 
 * a ninguno de los caracteres actualmente en pantalla, pero sí afecta 
 * aquéllas mostradas por funciones que usan el vídeo directamente para la 
 * salida en modo texto después de llamar a la función normvideo.
 */
//void normvideo();

/**
 * NOTE textcolor
 * Esta función selecciona el color de texto especificado por el argumento 
 * color. Esta función solamente funciona con aquellas funciones que envían 
 * datos de salida en modo texto directamente a la pantalla. El argumento 
 * color es un número entero entre 0 y 15 y el número 128, para activar el 
 * parpadeo; también se pueden usar constantes simbólicas definidas en conio.h 
 * en lugar de enteros. La función textcolor no afecta a ninguno de los 
 * caracteres actualmente en pantalla, pero sí afecta aquéllas mostradas por 
 * funciones que usan el vídeo directamente para la salida en modo texto 
 * después de llamar a la función textcolor.
 *
 * Existen varias constantes simbólicas de colores para usar.
 */
void textcolor(uint8_t color) __z88dk_fastcall;

/**
 * NOTE textbackground
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
void textbackground(uint8_t color) __z88dk_fastcall;

/**
 * TODO textblink
 * Activa o desactiva el parpadeo en el texto a escribir a partir de esta
 * llamada.
 * ==0 - Para desactivarlo
 * !=0 - Para activarlo
 */
//void textblink(uint8_t enabled) __z88dk_fastcall;

/**
 * NOTE textattr
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
void textattr(uint16_t attribute) __z88dk_fastcall;

// ANCHOR =====================================================================
// Screen positions & areas

/**
 * TODO window
 * Define una ventana de texto en pantalla especificado por los argumentos 
 * izquierda y superior, que describen la esquina superior izquierda y por los 
 * argumentos derecha e inferior, que describen la esquina inferior derecha. 
 * El tamaño mínimo de la ventana de texto es una columna por una fila. La 
 * ventana por defecto es la pantalla completa con la esquina superior 
 * izquierda siendo (0,0) y la inferior derecha siendo (C,F); donde C es menor 
 * al número columnas y F menor al número filas según el modo de texto en uso.
 * La llamada a la función window será ignorada si alguno de los argumentos no 
 * son válidos.
 */
//void window(int izquierda, int superior, int derecha, int inferior);

/**
 * NOTE gotoxy
 * Mueve el cursor de la ventana de texto a la posición según las coordenadas 
 * especificadas por los argumentos x e y. Si las coordenadas no son válidas 
 * entonces la llamda a la función gotoxy es ignorada.
 */
void gotoxy(uint8_t x, uint8_t y);

/**
 * NOTE wherex
 * Obtiene la coordenada x de la posición del cursor actual (dentro de la 
 * ventana de texto en uso).
 * 
 * @return	La función wherex retorna un número entero entre 0 y menor al 
 * 			número de columnas en el modo de texto en uso.
 */
int wherex();

/**
 * NOTE wherey
 * Obtiene la coordenada y de la posición del cursor actual (dentro de la 
 * ventana de texto en uso).
 * 
 * @return	La función wherey retorna un número entero entre 0 y menor al 
 * 			número de filas en el modo de texto en uso.
 */
int wherey();

/**
 * TODO gettext
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
//int gettext(int izquierda, int superior, int derecha, int inferior, void *destino);

/**
 * TODO puttext
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
//int puttext(int izquierda, int superior, int derecha, int inferior, void *origen);

/**
 * TODO movetext
 * Copia el contenido en un rectángulo de texto en pantalla definido por los 
 * argumentos izquierda y superior, que describen la esquina superior izquierda
 * y por los argumentos derecha e inferior, que describen la esquina inferior 
 * derecha, a otro rectángulo de iguales dimensiones. La esquina superior 
 * izquierda del nuevo rectángulo está especificada por los argumentos 
 * destino_izquierda y destino_superior. Todas las coordenadas son coordenadas 
 * absolutas de pantalla; no son relativas a la ventana. Los rectángulos que 
 * ocupan el mismo área son mudados acordemente. La función movetext usa la 
 * salida de vídeo directamente.
 * 
 * @return	La función movetext retorna un valor distinto a 0, si la operación tiene éxito. Si ocurre un error, como es el caso de acceder fuera de la pantalla, entonces retorna el valor de 0.
 */
//int movetext(int izquierda, int superior, int derecha, int inferior, int destino_izquierda, int destino_superior);


// ANCHOR =====================================================================
// Output to console functions

/**
 * NOTE putch
 * Muestra un carácter, especificado por el argumento c, directamente a la 
 * ventana de texto en uso. La función putch usa el vídeo directamente para 
 * mostrar caracteres. Esto se realiza mediante una escritura directa a la 
 * memoria de la pantalla o mediante una llamada a la BIOS, dependiendo del 
 * valor de la variable global _directvideo. Esta función no convierte los 
 * caracteres de nueva línea (\n) en la pareja de caracteres de retorno de 
 * línea/nueva línea (\r\n).
 *
 * @return	Retorna el carácter mostrado, si tiene éxito; si ocurre un error, 
 * 			entonces retorna EOF.
 */
uint8_t putch(uint8_t c) __z88dk_fastcall;

/**
 * TODO cprintf
 * Muestra texto en pantalla según el formato descrito. Esta función es 
 * similar a la función printf, pero con la excepción de que la función 
 * cprintf no convertirá los caracteres de nueva línea (\n) en la pareja de 
 * caracteres de retorno de línea/nueva línea (\r\n). Los caracteres de 
 * tabulación (\t) no serán expandidos a espacios. La cadena de texto con 
 * formato será enviado directamente a la ventana de texto actual en la 
 * pantalla.
 *
 * Esto se realiza mediante una escritura directa a la memoria de la pantalla.
 *
 * @return	Retorna el número de caracteres mostrados en pantalla.
 */
//int cprintf(const char *formato, ...);

/**
 * NOTE cputs
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
uint8_t cputs(const uint8_t *cadena) __z88dk_fastcall;

/**
 * NOTE clrscr
 * Esta función despeja la ventana de texto actual y coloca el cursor en la 
 * esquina superior izquierda: posición (0,0).
 *
 * Initial screen position in original conio library is (1,1).
 */
void clrscr();

/**
 * NOTE clreol
 * Esta función despeja todos los caracteres desde la posición del cursor 
 * hasta el final de la línea dentro de la ventana de texto actual, sin mover 
 * la posición del cursor.
 */
void clreol();

/**
 * NOTE insline
 * Inserta una línea vacía en la ventana de texto en la posición del cursor 
 * usando el color de fondo de texto en uso. Todas las líneas debajo de la 
 * vacía son mudadas una línea más abajo, y la línea inferior es mudada fuera 
 * de la ventana.
 */
void insline();

/**
 * NOTE delline
 * Borra la línea donde se encuentre el cursor y mueve todas las líneas 
 * inferiores a una línea anterior. La función delline funciona en la ventana 
 * de texto activa.
 */
void delline();


// ANCHOR =====================================================================
// Input from keyboard functions

/**
 * NOTE kbhit
 * Revisa si una tecla pulsada está disponible. Cualesquier pulsadas 
 * disponibles pueden ser recogidas con las funciones getch o getche.
 * 
 * @return	La función kbhit retorna 0 si no se ha registrado una pulsación 
 * 			de tecla; si hay una disponible, entonces el valor retornado es 
 * 			distinto a cero.
 */
int kbhit();

/**
 * NOTE getch
 * Lee un solo carácter directamente desde el teclado, sin mostrar tal 
 * carácter en pantalla.
 * 
 * @return	Retorna el carácter leído desde el teclado.
 */
int getch();

/**
 * NOTE getche
 * Lee un solo carácter directamente desde el teclado, mostrando tal carácter 
 * en pantalla, directamente a vídeo.
 *
 * @return	La función getche retorna el carácter leído del teclado.
 */
int getche();

/**
 * TODO ungetch
 * Empuja el carácter especificado por el argumento c de vuelta a la consola, 
 * forzando el carácter empujado, c, a ser el siguiente carácter leído. La 
 * función ungetch no funciona si es llamada más de una vez antes de la 
 * siguiente lectura.
 * 
 * @return	La función ungetch retorna el carácter empujado, si tiene éxito; 
 * 			si no, entonces retorna EOF.
 */
//int ungetch(int c) __z88dk_fastcall;

/**
 * TODO cgets
 * Esta función leerá una cadena de caracteres desde la consola, guardando la 
 * cadena (y su longitud) en el lugar apuntado por *cadena. La función cgets 
 * leerá caracteres hasta que encuentre una combinación de retorno de línea y 
 * nueva línea (CR/LF), o hasta que el número máximo de caracteres permitidos 
 * hayan sido leídos. Si se lee una combinación CR/LF, entonces es sustituido 
 * por un carácter nulo '\0' antes de ser guardado la cadena.
 * 
 * Antes de que la función cgets es llamada, asigna a cadena[0] la longitud 
 * máxima de la cadena a ser leída. Al retornar, cadena[1] es asignado el 
 * número de caracteres leídos. Los caracteres leídos comienzan a partir de 
 * cadena[2] (incluido) y termina con carácter nulo. Por esta razón, *cadena 
 * debe ser como mínimo cadena[0] más 2 bytes de longitud.
 * 
 * @return	Retorna la cadena de caracteres a partir de cadena[2], si tiene 
 * 			éxito.
 */
//char *cgets(char *cadena) __z88dk_fastcall;

/**
 * TODO getpass
 * Lee una contraseña desde la consola del sistema después de mostrar un 
 * mensaje, el cual es una cadena de caracteres (terminada en un carácter 
 * nulo) apuntada por el argumento message y desactivando la salida de texto.
 * 
 * @return	Retorna un puntero estático a la cadena de caracteres con el 
 * 			carácter nulo al final conteniendo la contraseña. Esta cadena 
 * 			contiene hasta ocho caracteres, sin contar el carácter nulo. Cada 
 * 			vez que la función getpass es llamada, la cadena de caracteres es 
 * 			sobrescrita.
 */
//char *getpass(const char *message) __z88dk_fastcall;

/**
 * TODO cscanf
 * Recoge el texto y lo procesa según el formato dado por *formato. Esta 
 * función es similar a la función scanf., la diferencia está en que la 
 * función cscanf lee los datos desde la consola que son automáticamente 
 * mostrados.
 * 
 * @return	Retorna el número de elementos entrados que hayan sido escaneados, 
 * 			convertidos, y guardados con éxito; el valor retornado no incluye 
 * 			elementos que no hayan sido guardados. Si no se han guardado 
 * 			elementos leídos, el valor de retorno es 0. Si cscanf intenta leer 
 * 			al final-de-fichero, el valor retornado es EOF.
 */
//int cscanf(const char *formato, ...);


// ANCHOR =====================================================================
// I/O functions

/**
 * TODO inport
 * Lee 1 byte de la parte baja de 1 palabra (word) desde el puerto de entrada 
 * indicado por el argumento id_puerto; lee el byte alto desde id_puerto+1. La 
 * función inport funciona de la misma manera que la instrucción 80x86 IN.
 * 
 * @return	Retorna el valor leído de una palabra (word) de tamaño desde el 
 *			puerto apuntado por el argumento id_puerto e id_puerto+1.
 */
//int inport(int id_puerto) __z88dk_fastcall;

/**
 * TODO outport
 * Escribe el último byte de 1 palabra (word) al puerto de salida indicado por 
 * el argumento id_puerto; escribe el primer byte a id_puerto+1. La función 
 * outport funciona de la misma manera que la instrucción 80x86 OUT.
 * 
 * @return	Retorna el valor escrito de una palabra (word) de tamaño al puerto 
 * 			apuntado por el argumento id_puerto e id_puerto+1.
 */
//int outport(int id_puerto, int valor);

/**
 * NOTE inportb
 * Lee 1 byte desde el puerto indicado por el argumento id_puerto.
 */
uint8_t inportb(uint8_t id_puerto) __z88dk_fastcall;

/**
 * NOTE outportb
 * Escribe 1 byte al puerto de salida indicado por el argumento id_puerto.
 */
void outportb(uint8_t id_puerto, uint8_t valor);



#endif //__CONIO_H__
