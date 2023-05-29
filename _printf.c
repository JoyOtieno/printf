#include "main.h"
/**
*print_buffer - Function that prints contents of the buffer array
*up to the buffer index specified by buff_ind
*@buffer: The buffer array
*@buff_ind: The buffer index
*
*Description: Function receives buffer array 'buffer' and buffer index
*buff_ind. It then loops from index 0 to the last one printing all
*characters and a new line using _printf
*/
void print_buffer(char buffer[], int *buff_ind);

/**
*_printf - Function that produces output according to format
*@format: A string pointer to desired output type
*
*Description: This function parses format processing it character
*by character. It then performs formattimg operations using
*placeholders before printing output
*
*Return: The number of characters to be printed
*/

int _printf(const char *format, ...)
{
	int t, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list nums;
	char buffer[BSIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(nums, format);

	for (t = 0; format && format[t] != '\0'; t++)
	{
		if (format[t] != '%')
		{
			buffer[buff_ind++] = format[t];
			if (buff_ind == BSIZE)
			{
			print_buffer(buffer, &buff_ind);
			printed_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &t);
			width = get_width(format, &t, nums);
			precision = get_precision(format, &t, nums);
			size = get_size(format, &t);
			++t;
			printed = handle_print(format, &t, nums, buffer,
			flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(nums);
	return (printed_chars);
}
/**
*print_buffer - Function that prints contents of the buffer array
*up to the buffer index specified by buff_ind
*@buffer: The buffer array
*@buff_ind: The buffer index
*
*Description: Function receives buffer array 'buffer' and buffer index
*buff_ind. It then loops from index 0 to the last one printing all
*characters and a new line using _printf
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}







