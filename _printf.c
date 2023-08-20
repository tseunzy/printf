#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    int count = 0, buff_ind = 0;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    for (int i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            print_buffer(buffer, &buff_ind);
            int flags = get_flags(format, &i);
            int width = get_width(format, &i, args);
            int precision = get_precision(format, &i, args);
            int size = get_size(format, &i);
            int printed = handle_print(format, &i, args, buffer,
                                       flags, width, precision, size);
            if (printed == -1)
                return -1;
            count += printed;
        }
        else
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            else
                count++;
        }
    }
    print_buffer(buffer, &buff_ind);
    va_end(args);
    return count;
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);

    *buff_ind = 0;
}