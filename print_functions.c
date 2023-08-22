#include "main.h"

/**
 * printString - Outputs a string
 * @args: List of arguments
 * @buffer: Buffer array to handle output
 * @flags: Determines the active flags
 * @width: Specifies the width of the output
 * @precision: Specifies the precision of the output
 * @size: Specifies the size of the output
 * Return: The number of characters outputted
 */
int printString(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str = va_arg(args, char *);
	int length = 0, k;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = (precision >= 6) ? "      " : "(null)";
	}
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/************************* PRINT CHAR *************************/

/**
 * printCharacter - Outputs a single character
 * @args: A list of arguments
 * @buffer: A buffer array to handle the output
 * @flags: Determines the active flags
 * @width: Specifies the width of the output
 * @precision: Specifies the precision of the output
 * @size: Specifies the size of the output
 * Return: The number of characters outputted
 */
int printCharacter(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char ch = (char)va_arg(args, int);

	return (handlewritechar(ch, buffer, flags, width, precision, size));
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * printPercent - Outputs a percent sign
 * @args: Argument list
 * @buffer: Buffer array to handle output
 * @flags: Determines the active flags
 * @width: Specifies the width of the output
 * @precision: Specifies the precision of the output
 * @size: Specifies the size of the output
 * Return: The number of characters outputted
 */
int printPercent(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/************************* PRINT INT *************************/

/**
 * printInteger - Outputs an integer
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printInteger(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int it_nega = 0;
	long int n = va_arg(args, long int);
	unsigned long int numb;

	n = convertsizenumber(n, size);

	if (n == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int)(-n);
		it_nega = 1;
	}

	while (numb > 0)
	{
		buffer[k--] = (char)((numb % 10) + '0');
		numb /= 10;
	}

	k++;

	return (writenumber(it_nega, k, buffer, flags, width, precision, size));
}


/************************* PRINT BINARY *************************/
/**
 * printBinary - Outputs an unsigned number in binary format
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printBinary(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int q, r = va_arg(args, unsigned int);
	unsigned int b[32];
	int counter, total, k;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	q = 2147483648; /* (2 ^ 31) */
	b[0] = r / q;
	for (k = 1; k < 32; k++)
	{
		q /= 2;
		b[k] = (r / q) % 2;
	}
	for (k = 0, total = 0, counter = 0; k < 32; k++)
	{
		total += b[k];
		if (total || k == 31)
		{
			char newchar = '0' + b[k];

			write(1, &newchar, 1);
			counter++;
		}
	}
	return (counter);
}

