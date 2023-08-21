#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int k, pfrinted = 0, fprinted_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (k = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			pfrinted = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (fprinted == -1)
				return (-1);
			fprinted_chars += pfrinted;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (fprinted_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffa: Array of chars
 * @buff_inid: Index at which to add next char, represents the length.
 */
void print_buffer(char buffa[], int *buff_inid)
{
	if (*buff_inid > 0)
		write(1, &buffa[0], *buff_inid);

	*buff_inid = 0;
}

