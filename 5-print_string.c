#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_string -prints string with formatting options
 * @string: string to print
 * @width:width.
 * @precision: precision
 * @nums: arguements
 * @buffer: buffer array
 * @size: size
 * @flags: flags
 *
 * Return: characters
 */

int print_string(va_list nums, char buffer[],
		int precision, int flags, int width, int size)
{
	char *string;
	int length = 0, printed_characters = 0;

	UNUSED(buffer), UNUSED(flags), UNUSED(size);
	UNUSED(precision), UNUSED(width);
	
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= MIN_PRECISION)
			string = " ";
	}
	while (string[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (printed_characters = width - length; printed_
					characters > 0; printed_characters--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (printed_characters = width - length; printed_
					characters > 0; printed_characters--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
		}
	}
	return (write(1, string, length));
}

