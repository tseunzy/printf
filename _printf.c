#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int k, pfrinted = 0, fprinted_chars = 0;
	int flags, width, precision, size, buff_inid = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_inid++] = format[k];
			if (buff_inid == BUFF_SIZE)
				print_buffer(buffer, &buff_inid);
			/* write(1, &format[k], 1);*/
			fprinted_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_inid);
			flags = get_flags(format, &k);
			width = get_width(format, &k, list);
			precision = get_precision(format, &k, list);
			size = get_size(format, &k);
			++k;
			pfrinted = handle_print(format, &k, list, buffer,
				flags, width, precision, size);
			if (pfrinted == -1)
				return (-1);
			fprinted_chars += pfrinted;
		}
	}

	print_buffer(buffer, &buff_inid);

	va_end(list);

	return (fprinted_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffa: Array of chars
 * @buff_inid: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_inid)
{
	int chars_to_write = (*buff_inid > 0) ?  *buff_inid : 0;

	write(1, buffer, chars_to_write);

	*buff_inid = 0;
}
