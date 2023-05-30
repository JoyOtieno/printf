#include "main.h"
#include <unistd.h>

/**
 * print_percentage - prints percentage sign
 * @buffer: buffer array
 * @nums: arguments
 * @precision: precision
 * @flags: flags
 * @width: width
 * @size: size
 * Return: characters printed
 */

int print_percent(va_list nums, char buffer[],
int precision, int flags, int width, int size)
{
	int result;
	(void)nums;
	(void)precision;
	(void)flags;
	(void)width;
	(void)size;

	result = write(1, "%%", 1);

	return (result);
}
