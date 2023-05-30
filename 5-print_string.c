#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_string -prints string with formatting options
 * @str: string to print
 * @width:width.
 * @precision: umber of characters to print
 * @flags: formattingg flags
 *
 * Return: characters
 */

int print_string(const char *str, int width, int precision, int flags)
{
	int padding, int length = 0, int printed_characters = 0;

	if (str == NULL)
		str = "(null)";
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
	length = precision;
	if (width > length)
	{
		int padding = width - length;

		if (flags & F_MINUS)
		{
			write(1, str, length);
			while (padding > 0)
			{
				write(1, " ", 1);
				padding--;
				printed_characters++;
			}
		}
		else
		{
			while (padding > 0)
			{
				write(1, " ", 1);
				padding--;
				printed_characters++;
			}
			write(1, str, length);
		}
	printed_characters += length;
	}
	else
	{
		write(1, str, length);
		printed_characters = length;
	}
	return (printed_characters);
}
