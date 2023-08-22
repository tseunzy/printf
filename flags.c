#include "main.h"
/**
 * get_flags - Determines active flags
 * @format: Format string for output
 * @k: Parameter index
 * Return: Active flags
 */
int get_flags(const char *format, int *k)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_k] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*k = curr_k - 1;

	return (flags);
}
