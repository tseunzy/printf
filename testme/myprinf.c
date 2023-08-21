#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...);
int (*pick(char ch))(va_list);
int _char(va_list args);
int _string(va_list args);
int _percent(va_list args);
int myputchar(int x, int count);


int _char(va_list args)
{ /* handlers of 'c'*/
	char vim = va_arg(args, int);

	putchar(vim);
	return (1);
}

int _string(va_list args)
{ /* handlers of 's'*/
	int num = 0; /* no of count of char to the string*/
	char *vim = va_arg(args, char *);

	while (*vim != '\0')
	{
		putchar(*vim);
		vim++;
		num++;
	}
	return (num);
}

int _percent(va_list args)
{
	char symbol = (char) va_arg(args, int);

	putchar(symbol);
	return (symbol);
}
int (*picker(char ch))(va_list)
{
	if (ch == 's')
	{
		return (&_string);
	}
	else if (ch == 'c')
	{
		return (&_char);
	}
	else if (ch == '%')
	{
		return (&_percent);
	}
}



int _printf(const char *format, ...)
{
	int count = 0;
	char specifier;

	va_list noargs;
	int i = 0;

	va_start(noargs, format);

	if (format[0] == '\0')
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			specifier = format[i + 1];
			count = count + (*picker(specifier))(noargs);
			i++;
		}
		else
		{
			putchar(format[i]);
			count = count + 1;
		}
		i++;
	}
	return (count);
}

int myputchar(int x, int count)
{
	int c1 = x;

	if (x < 0)
	{
		c1 = -x;
		putchar('-');
		count = count + 1;
	}
	if (c1 / 10)
	{
		count = myputchar(c1 / 10, count);
	}

	putchar(c1 % 10 + '0');

	return (count + 1);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Let's try to printf a simple sentence.\n");
int (*picker(char ch))(va_list)
{
        if (ch == 's')
        {
                return (&_string);
        }
        else if (ch == 'c')
        {
                return (&_char);
        }
        else if (ch == '%')
        {
                return (&_percent);
        }
}	printf("Let's try to printf a simple sentence.\n");
	printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	return (0);
}
