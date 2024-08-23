#include <stdarg.h>
#include <stdint.h>
#include "conio.h"

static void _printn(unsigned u, unsigned base, char issigned);
static void _printn_long(uint32_t u, unsigned base, char issigned);
static void _printf(const char *format, va_list va);

static char *_str;
static char _buffer[10];
static int _idx = 0;

/*
	Simple cprintf implementation.
	Supports %s %c %u %d %l %x %b
*/
int cprintf(const char *format, ...)
{
	va_list va;
	va_start(va, format);

	_str = 0;
	_printf(format, va);

	/* return printed chars */
	return 0;
}

/*
	Simple csprintf implementation.
	Supports %s %c %u %d %l %x %b
*/
int csprintf(char *str, const char *format, ...)
{
	va_list va;
	va_start(va, format);

	_str = str;
	_printf(format, va);
	*_str = '\0';

	/* return formatted chars */
	return _str - str;
}

const char const _hex[] = "0123456789ABCDEF";

static void _putch(char c)
{
	if (_str == 0) {
		putch(c);
		return;
	}
	*_str++ = c;
	return;
}

static void _printn(unsigned u, unsigned base, char issigned)
{
	if (issigned && ((int)u < 0)) {
		_putch('-');
		u = (unsigned)-((int)u);
	}

	do {
		_buffer[_idx++] = _hex[u % base];
		u /= base;
	} while (u);
	while (_idx) {
		_putch(_buffer[--_idx]);
	}
}

static void _printn_long(uint32_t u, unsigned base, char issigned)
{
	if (issigned && ((int32_t)u < 0)) {
		_putch('-');
		u = (uint32_t)-((int32_t)u);
	}

	do {
		_buffer[_idx++] = _hex[u % base];
		u /= base;
	} while (u);
	while (_idx) {
		_putch(_buffer[--_idx]);
	}
}

static void _printf(const char *format, va_list va)
{
	while (*format) {
		if (*format == '%') {
			switch (*++format) {
				case 'c': {
					char c = (char)va_arg(va, int);
					_putch(c);
					break;
				}
				case 'u': {
					unsigned u = va_arg(va, unsigned);
					_printn(u, 10, 0);
					break;
				}
				case 'd': {
					unsigned u = va_arg(va, unsigned);
					_printn(u, 10, 1);
					break;
				}
				case 'l': {		// %lu / %ld
					uint32_t u = va_arg(va, uint32_t);
					format++;
					if (*format == 'u') {
						_printn_long(u, 10, 0);
					} else
					if (*format == 'd') {
						_printn_long(u, 10, 1);
					}
					break;
				}
				case 'x': {
					unsigned u = va_arg(va, unsigned);
					_printn(u, 16, 0);
					break;
				}
				case 'b': {
					unsigned u = va_arg(va, unsigned);
					_printn(u, 2, 0);
					break;
				}
				case 's': {
					char *s = va_arg(va, char *);
					while (*s) {
						_putch(*s);
						s++;
					}
				}
			}
		} else {
			_putch(*format);
		}
		format++;
	}
	return;
}
