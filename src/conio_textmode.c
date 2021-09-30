#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
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
void textmode(uint8_t mode) __z88dk_fastcall
{
	switch (mode) {
		case BW40:
			_current_text_info.currmode = mode;
			_current_text_info.screenwidth = 40;
			_current_text_info.screenheight = 24;
			_current_text_info.vramCharMap = 0x0000;
			break;

		case BW80:
			_current_text_info.currmode = mode;
			_current_text_info.screenwidth = 80;
			_current_text_info.screenheight = 24;
			_current_text_info.vramCharMap = 0x0000;
			break;

		default:
			return;
	}
	_current_text_info.normattr = ADDR_POINTER_BYTE(BAKCLR) | (ADDR_POINTER_BYTE(FORCLR)<<4);
	_current_text_info.attribute = _current_text_info.normattr;

	ADDR_POINTER_BYTE(LINL40) = _current_text_info.screenwidth;
	ADDR_POINTER_BYTE(CRTCNT) = _current_text_info.screenheight;
	__asm
		ld ix,#INITXT
		BIOSCALL
	__endasm;
}
