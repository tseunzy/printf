#include "main.h"

/**
 *
 */

int _char(va_list args)
{ /* handlers of 'c'*/
        char vim = va_arg(args, int);

        putchar(vim);
        return (1);
}

/**
 *
 */

int _string(va_list args)
{ /* handlers of 's'*/
        int num = 0; /* no of count of char to the string*/
        char *vim = va_arg(args, char *);

        while (*vim != '\0')
        {
                putchar(*vim);
                vim++;
                num++;
        }
        return (num);
}
/**
 *
 */

int _percent(va_list args)
{
        char symbol = (char) va_arg(args, int);

        putchar(symbol);
        return (symbol);
}
