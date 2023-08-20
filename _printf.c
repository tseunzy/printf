#include "main.h"
/**
 * _printf - program on _printf function
 * @format: format
 * Return: No of printed chars;
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int i, count = 0;
	char specifier, c, *str, *str_r;
	int str_len;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
			switch (specifier)
			{
				case 'c':
					c = (char) va_arg(args, int);
					putchar(c);
					count++;
					break;

				case 's':
					*str = va_arg(args, char *);
					fputs(str, stdout);
					count += strlen(str);
					break;

				case '%':
					putchar('%');
					count++;
					break;

				case 'r':
					*str_r = va_arg(args, char *);
					str_len = strlen(str_r);
					for (i = str_len - 1; i >= 0; i--)
					{
						putchar(str_r[i]);
						count++;
					}
					break;

				default:
					putchar('%');
					putchar(specifier);
					count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
