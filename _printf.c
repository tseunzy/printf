#include "main.h"

/**
 *
 */

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
