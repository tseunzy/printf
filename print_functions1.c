#include "main.h"

/************************* UNSIGNED NUMBER *************************/
/**
 * printUnsigned - Outputs an unsigned number
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printUnsigned(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(args, unsigned long int);

	numb = convertsizeunsgnd(numb, size);

	if (numb == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[k--] = (numb % 10) + '0';
		numb /= 10;
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/***UNSIGNED NUMBER IN OCTAL**********/
/**
 * printOctal - Outputs an unsigned number in octal notation
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printOctal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(args, unsigned long int);
	unsigned long int initNumb = numb;

	UNUSED(width);

	numb = convertsizeunsgnd(numb, size);

	if (numb == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[k--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && initNumb != 0)
		buffer[k--] = '0';

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/****** UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * printHexadecimal - Outputs an unsigned number in hexadecimal notation
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printHexadecimal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (printHexa(args, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * printHexaUpper - Outputs an unsigned number in uppercase hexadecimal notatN
 * @args: Argument list
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printHexaUpper(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	return (printHexa(args, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * printHexa - Outputs a hexadecimal number in lowercase or uppercase
 * @args: Argument list
 * @mapTo: Array of values to map the number to
 * @buffer: Buffer array for output handling
 * @flags: Determines active flags
 * @flagCh: Determines active flags
 * @width: Specifies output width
 * @precision: Specifies output precision
 * @size: Specifies output size
 * Return: Number of characters printed
 */
int printHexa(va_list args, char mapTo[], char buffer[],
		int flags, char flagCh, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(args, unsigned long int);
	unsigned long int initNumb = numb;

	UNUSED(width);
	numb = convertsizeunsgnd(numb, size);

	if (numb == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		buffer[k--] = mapTo[numb % 16];
		numb /= 16;
	}
	if (flags & F_HASH && initNumb != 0)
	{
		buffer[k--] = flagCh;
		buffer[k--] = '0';
	}
	k++;
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

