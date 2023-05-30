#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
* print_int-prints integer
* @nums: integer
* @width: width
* @precision: precision
* @flags: flags
* @buffer: buffer array
* @size: size
* Return: printed characters
*/

int print_int(va_list nums, char buffer[], int size,
int width, int precision, int flags)
{
	unsigned long int var;
	int index = 0, int negative_flag = 0;

	long int value = va_arg(nums, long int);

	value = convert_size_number(value, size);

	if (value == 0)
		buffer[index--] = '0';

	buffer[0] = '\0';
	var = (unsigned long int)value;

	if (value < 0)
	{
		var = (unsigned long int)((-1) * value);
		negative_flag = 1;
	}

	while (var > 0)
	{
		buffer[index--] = (var % 10) + '0';
		var /= 10;
	}

	index++;

	return (write_number(buffer, size, width, precision, flags, negative_flags));
}
