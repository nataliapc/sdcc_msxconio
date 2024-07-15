#include "conio.h"


/**
 * Displays the string, which ends with the null character, pointed to by the
 * *cadena argument in the current text window. This function is similar to
 * the puts function, but with two exceptions: the cputs function will not add
 * the newline character at the end of the text.
 * 
 * This is done by directly writing to the screen memory.
 */
void cputs(const char *str)
{
	while (*str) putch(*str++);
}
