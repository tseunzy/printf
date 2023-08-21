#include "main.h"

/**
 *
 */

int myputchar(int x, int count)
{
        int c1 = x;

        if (x < 0)
        {
                c1 = -x;
                putchar('-');
                count = count + 1;
        }
        if (c1 / 10)
        {
                count = myputchar(c1 / 10, count);
        }

        putchar(c1 % 10 + '0');

        return (count + 1);
}
