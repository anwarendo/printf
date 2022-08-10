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
	int d;
	int d1;
	int sign;
	char *dstr;
	int dsize;
	int i;
	int j;
	int c_cnt;

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
                       /* This section is for Task 1 */
			else if (format[i] == 'd' || format[i] == 'i')
			{
				i++;
				sign = 1;
				d = va_arg(ap, int);
				if (d < 0)
					sign = -1 * sign;
				d = sign * d;
				dsize = 0;
				d1 = d;
				while (d1  > 0)
				{
					dsize++;
					d1 = d1 / 10;
				}

				dstr = malloc(dsize);
				if (dstr)
				{
					d1 = d;
					j = dsize - 1;
					while (j >= 0)
					{
						dstr[j] = (d1 % 10) + '0';
						j--;
						d1 = d1 / 10;
					}

					if (sign < 0)
					{
						_putchar('-');
						c_cnt++;
					}

					while (j <= dsize)
					{
						_putchar(dstr[j]);
						j++;
						c_cnt++;
					}
				}
				free(dstr);
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
