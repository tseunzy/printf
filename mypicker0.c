#include "main.h"

/**
 *
 */
int (*picker(char ch))(va_list)
{
        if (ch == 's')
        {
                return (&_string);
        }
        else if (ch == 'c')
        {
                return (&_char);
        }
        else if (ch == '%')
        {
                return (&_percent);
        }
}
