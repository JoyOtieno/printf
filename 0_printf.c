#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 *_prinf- produces output as per format
 *@format: format
 *Return: printed characters
 */
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int num_characters_printed = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format != '%') {
            write(1, format, 1);
            num_characters_printed++;
        } else {
            format++;

            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                   
		    write(1, &c, sizeof(int));
                    num_characters_printed++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char*);
                   
		    int len = 0;
                    while (str[len] != '\0')
                        len++;
                    write(1, str, len);
                    num_characters_printed += len;
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    int sign = 0;
                    if (num < 0) {
                        sign = 1;
                        num *= -1;
                    }
                    int temp = num;
                    int digits = 0;
                    do {
                        digits++;
                        temp /= 10;
                    } while (temp != 0);

                    if (sign) {
                        write(1, "-", 1);
                        num_characters_printed++;
                    }

                    char buffer[10];
                    int index = digits - 1;
                    do {
                        buffer[index--] = (num % 10) + '0';
                        num /= 10;
                    } while (num != 0);

                    write(1, buffer, digits);
                    num_characters_printed += digits;
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    
		    unsigned int temp = num;
                    int digits = 0;
                    do {
                        digits++;
                        temp /= 10;
                    } while (temp != 0);

                    char buffer[10];
                    int index = digits - 1;
                    do {
                        buffer[index--] = (num % 10) + '0';
                        num /= 10;
                    } while (num != 0);

                    write(1, buffer, digits);
                    num_characters_printed += digits;
                    break;
                }
                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    unsigned int temp = num;
                    int digits = 0;
                    do {
                        digits++;
                        temp /= 8;
                    } while (temp != 0);

                    char buffer[12];
                    int index = digits - 1;
                    do {
                        buffer[index--] = (num % 8) + '0';
                        num /= 8;
                    } while (num != 0);

                    write(1, buffer, digits);
                    num_characters_printed += digits;
                    break;
                }
                case 'x':
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    unsigned int temp = num;
                    int digits = 0;
                    do {
                        digits++;
                        temp /= 16;
                    } while (temp != 0);

                    char buffer[12];
                    int index = digits - 1;
                    do {
                        int remainder = num % 16;
                        if (remainder < 10)
                            buffer[index--] = remainder + '0';
                        else if (*format == '

