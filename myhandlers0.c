#include "main.h"

/**
 *
 */

int _char(va_list args)
{ /* handlers of 'c'*/
        char vim = va_arg(args, int);

        _putchar(vim);
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
                _putchar(*vim);
                vim++;
                num++;
        }
        return (num);
}

/**
 *
 */
int _decimal(va_list arg)
{
	int num = 0;
	int vim = va_arg(arg, int);

	num = _putchar(vim, 0);
	return (num);
}
/**
 *
 */

int _percent(va_list args)
{
        char symbol = va_arg(args, int);

        _putchar(symbol);
        return (symbol);
}
