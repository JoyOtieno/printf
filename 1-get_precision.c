#include "main.h"

/**
 * is_digit -checkss if  character is digit
 * @c: character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
 /**
 * get_precision -gets precision in printing
 * @format: format string
 * @t: pointer to current place in string
 * @nums: arguments
 * Return: precision
 */

int get_precision(const char *format, int *t, va_list nums)
{
	int curr_t = *t + 1;

	int precision = -1;

	if (format[curr_t] != '.')
		return (precision);

	precision = 0;

	for (curr_t += 1; format[curr_t] != '\0'; curr_t++)
	{
		if (is_digit(format[curr_t]))
		{
			precision *= 10;
			precision += format[curr_t] - '0';
		}
		else if (format[curr_t] == '*')
		{
			curr_t++;
			precision = va_arg(nums, int);
			break;
		}
		else
			break;
	}

	*t = curr_t - 1;

	return (precision);
}
