#include "main.h"
#include <stdarg.h>

/**
* print_reverse -prints string in reverse
* @nums: arguments
* @buffer: buffer array
* @precision: precision
* @flags:  flags
* @width: width
* @size: size
* Return: characters printed
*/

int print_reverse(va_list nums, char buffer[],
int precision, int flags, int width, int size)
{
	int t;
	char *string;

	int index = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(nums, char *);

	if (string == NULL)
	{
		UNUSED(precision);
		string = ")Null(";
	}
	for (t = 0; string[t]; t++)
		;
		for (t = t - 1; t >= 0; t--)
		{
			char z = string[t];

			write(1, &z, 1);
			index++;
		}
	return (index);
}
