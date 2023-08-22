#include "main.h"

/**
 * get_precision - Determines the precs for printing
 * @format: Formatted string where arguments are printed
 * @k: Index within the formatted string
 * @args: Argument list to be printed
 *
 * Return: precision value
 */
int get_precision(const char *format, int *k, va_list args)
{
	int curr_k = *k + 1;
	int precision = -1;

	if (format[curr_k] != '.')
		return (precision);

	precision = 0;

	for (curr_k += 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_digit(format[curr_k]))
		{
			precision *= 10;
			precision += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (precision);
}
