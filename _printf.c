#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to a format string
 * Return: the number of characters printed except the null byte, '\0'
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char c;
	char *s;
	int i;
	int c_cnt;

	/* variable argument start i.e the "..." on the argument */
	va_start(ap, format);
	i = 0;
	c_cnt = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				continue;
			else if (format[i] == 'c')
			{
				i++;
				c = (char) va_arg(ap, int);
				_putchar(c);
				c_cnt++;
			}
			else if (format[i] == 's')
			{
				i++;
				s = va_arg(ap, char *);
				do {
					_putchar(*s);
					c_cnt++;
				} while (*s++ != '\0');
			}
			else
			{
				_putchar('%');
				c_cnt++;
			}
		}
		else
		{
			_putchar(format[i]);
			i++;
			c_cnt++;
		}
	}
	va_end(ap);
	return (c_cnt);
}
