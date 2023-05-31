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
	char *string, int padding, length = 0, printed_characters = 0;

	UNUSED(buffer), UNUSED(flags), UNUSED(size);
	string = va_arg(nums, char *);
	if (string == NULL)
		string = "(null)";
	while (string[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		padding = width - length;
		if (flags & F_MINUS)
		{
			write(1, string, length);
			while (padding > 0)
			{
				write(1, "\t", 1);
				padding--;
				printed_characters++;
			}
		}
		else
		{
			while (padding > 0)
			{
				write(1, "\t", 1);
				padding--;
				printed_characters++;
			}
			write(1, string, length);
		}
		printed_characters += length;
	}
	else
	{
		write(1, string, length);
		printed_characters = length;
	}
	return (printed_characters);
}
