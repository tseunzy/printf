#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * printPointer - Outputs the value of a pointer variable
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printPointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char extraC = 0, padd = ' ';
	int k = BUFF_SIZE - 2, length = 2, paddStart = 1; /* length=2, for '0x' */
	unsigned long numbAddrs;
	char mapTo[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numbAddrs = (unsigned long)addrs;

	while (numbAddrs > 0)
	{
		buffer[k--] = mapTo[numbAddrs % 16];
		numbAddrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extraC = '+', length++;
	else if (flags & F_SPACE)
		extraC = ' ', length++;

	k++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, k, length,
		width, flags, padd, extraC, paddStart));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * printNonPrintable - Outputs ASCII codes in hexadeci for non-printable char
 * @args: List of arguments
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printNonPrintable(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int k = 0, offkey = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[k] != '\0')
	{
		if (isprintable(str[k]))
			buffer[k + offkey] = str[k];
		else
			offkey += appendhexacode(str[k], buffer, k + offkey);
		k++;
	}
	buffer[k + offkey] = '\0';
	return (write(1, buffer, k + offkey));
}

/************************* PRINT REVERSE *************************/
/**
 * printReverse - Outputs a reversed string
 * @args: List of arguments
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */

int printReverse(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int k, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;

	for (k = k - 1; k >= 0; k--)
	{
		char newchar = str[k];

		write(1, &newchar, 1);
		counter++;
	}
	return (counter);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Outputs a string in rot13 encoding
 * @args: List of arguments
 * @buffer: Buffer array to manage output
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int print_rot13string(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char r;
	char *str;
	unsigned int k, j;
	int counter = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[k])
			{
				r = output[j];
				write(1, &r, 1);
				counter++;
				break;
			}
		}
		if (!input[j])
		{
			r = str[k];
			write(1, &r, 1);
			counter++;
		}
	}
	return (counter);
}

