#include "main.h"

/**
 * get_width - Computes the width for printing
 * @format: Format string for output
 * @k: Parameter index
 * @args: List of arguments to be printed
 *
 * Return: Width for printing
 */
int get_width(const char *format, int *k, va_list args)
{
	int curr_k;
	int width = 0;

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_digit(format[curr_k]))
		{
			width *= 10;
			width += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (width);
}
