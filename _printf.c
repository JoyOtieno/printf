#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;

	va_list characters;
	
	va_start(characters, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(characters, int));
					break;
				case 's':
				{
					const char *str = va_arg(characters, const char*);
					
					while (*str != '\0')
					{
						count += putchar(*str);
						str++;
					}
				}
				break;
			case '%':
				count += putchar('%');
				break;
			default:
				count += putchar('%');
				count += putchar(*format);
			break;
			}
		}
		else
		{
			count += putchar(*format);
		}
	format++;
	}
	va_end(characters);
	return (count);
}
