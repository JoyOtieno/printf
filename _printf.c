#include "main.h"

/**
*_printf - Function that produces output according to format
*print_buffer - Function that prints contents of the buffer array
*up to the buffer index specified by buff_ind
*Description: Function receives buffer array buffer[] and buffer index
* *buff_ind. It then loops from index 0 to the last one printing all
* characters and a new line using _printf
*@format: format of output
*Return: chars
*/
void print_buffer(char buffer[], int *buff_ind)
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
		buffer[buff_ind++] = format[t];
		if (buff_ind == BSIZE)
		{
			print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &t);
			width = get_width(format, &t, nums);
			precision = get_precision(format, &t, list);
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
















