#include "main.h"
#include <stdarg.h>

/**
 * get_width- gets width to print
 * @format: format string
 * @t: pointer to current place in string
 * @nums: arguments
 * Return: width
 */

int get_width(const char *format, int *t, va_list nums)
{
	int width = 0;
	int curr_t = *t + 1;

	if (format[curr_t] == '*')
	{
		width = va_arg(nums, int);
		curr_t++;
	}
	else
	{
		while (format[curr_t] != '\0' && is_digit(format[curr_t]))
		{
			width = width * 10 + (format[curr_t] - '0');
			curr_t++;
		}
	}

	*t = curr_t - 1;

	return (width);
}
