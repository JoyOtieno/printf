#include "main.h"
#include <stdarg.h>

/**
* print_char - Prints a char
* @buffer: buffer array
* @nums: arguments
* @precision: precision
* @flags:  flags
* @width: width
* @size: size
* Return: charaters printed
*/

int print_char(va_list nums, char buffer[],
int precision, int flags, int width, int size)
{
	char t = va_arg(nums, int);

	return (handle_write_char(t, buffer, precision
		, flags, width, precision, size));
}
