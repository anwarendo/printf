#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to a format string
 * Return: the number of characters printed except the null byte, '\0'
 */
int _printf(const char *format, ...)
{
	va_list ap;
/*	char c;
	char *s;
*/	int c_count;

	/* variable argument start i.e the "..." on the argument */
	va_start(ap, format);
	printf("%s", format);
	c_count = 0;
/*
	switch (*format++)
	{
	case 'c':
		c = (char) va_arg(ap, int);
		break;
	case 's':
		s = va_arg(ap, char *);
		break;
	}
*/
	va_end(ap);
	return (c_count);
}
