#include "main.h"

/**
 * get_size -gets size for printing
 * @format: format string
 * @t: pointer to current place in string
 * Return: size
 */

int get_size(const char *format, int *t)
{
	int size = 0;

	if (format[*t + 1] == 'l')
	{
		size = S_LONG;
		*t = *t + 1;
	}
	else if (format[*t + 1] == 'h')
	{
		size = S_SHORT;
		*t = *t + 1;
	}

	return (size);
}
