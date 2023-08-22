#include "main.h"
/**
 * get_size - Determines the casting size of the argument
 * @format: Formatted string where arguments are printed
 * @k: Index within the formatted string
 *
 * Return: Size of precision
 */
int get_size(const char *format, int *k)
{
	int curr_k = *k + 1;
	int size = 0;

	if (format[curr_k] == 'l')
		size = S_LONG;
	else if (format[curr_k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*k = curr_k - 1;
	else
		*k = curr_k;

	return (size);
}

