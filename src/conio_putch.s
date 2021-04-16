; Muestra un carácter, especificado por el argumento c, directamente a la 
; ventana de texto en uso. La función putch usa el vídeo directamente para 
; mostrar caracteres. Esto se realiza mediante una escritura directa a la 
; memoria de la pantalla o mediante una llamada a la BIOS, dependiendo del 
; valor de la variable global _directvideo. Esta función no convierte los 
; caracteres de nueva línea (\n) en la pareja de caracteres de retorno de 
; línea/nueva línea (\r\n).
; 
; @return	Retorna el carácter mostrado, si tiene éxito; si ocurre un error, 
; 			entonces retorna EOF.

;uint8_t putch(uint8_t c) __z88dk_fastcall;
_putch::
    ld e,l
    
    ld c,#0x02  ;CONOUT
    call 5

    ld l,e
    ld h,#0

    ret


_putchar::
    pop af
    pop de
    push de
    push af

    ld a,e
    cp #0x0a
    
    ld c,#0x02  ;CONOUT
    jp nz,.jumpPutchar

    call 5
    ld e,#0x0d
.jumpPutchar:
    call 5

    ld l, e
    ld h, #0

    ret
