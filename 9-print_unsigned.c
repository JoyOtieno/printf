#include <stdarg.h>
#include <stdio.h>

/**
* print_unsigned -prints unsigned numbers
* @nums: arguments
* @buffer: buffer array
* @precision: precision
* @flags:  flags
* @width: width
* @size: size
* Return: characters printed
*/

int print_unsigned(va_list nums, char buffer[],
int precision, int flags, int width, int size)
{
	int t = BUFF_SIZE - 2;
	unsigned long int value = va_arg(nums, unsigned long int);

	value = convert_size_unsgnd(num, size);

	if (valuem == 0)
		buffer[t--] = '0';

	buffer[BSIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[t--] = (value % 10) + '0';
		num /= 10;
	}

	t++;

	return (write_unsgnd(0, t, buffer, precision, flags, width, size));
}
