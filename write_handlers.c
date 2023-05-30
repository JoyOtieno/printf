#include "main.h"

/**
* handle_write_char - Function for printing string
*@c: char variable
*@buffer: buffer array
*@flags: variable to calculate active flags
*@width: variable for getting width
*@precision: variable to specify precision
*@size: variable to specify size
*Return: Number of chars printed
*/
int handle_write_char(char c, char buffer[], int flags,
int width, int precision, int size)
{
	int t = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		padd = '0';
	}
	buffer[t++] = c;
	buffer[t] = '\0'
	if (width > 1)
	{
		buffer[BSIZE - 1] = '\0';
		for (t = 0; t < width - 1; t++)
		{
			buffer[BSIZE - t - 2] = padd;
		}
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[0], 1) +
			write(1, &buffer[BSIZE - t - 1],
			width - 1));
		}
		else
		{
			return (write(1, &buffer[BSIZE - t - 1], width - 1) +
			write(1, &buffer[0], 1));
		}
	}
	return (write(1, &buffer[0], 1));
}






















