#include "main.h"
/**
* is_printable - Function to evaluate printable char
* @c: input char
* Return: 1 is c is printable, 0 otherwise
*/
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
}
/**
* append_hexa_code - Append to buffer hexadecimal code
* @buffer: char array
* @t: start point for appending
* @ascii_code: ASSCI CODE.
* Return: Always 3 (success)
*/
int append_hexa_code(char ascii_code, char buffer[], int t)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[t++] = '\\';
	buffer[t++] = 'x';
	buffer[t++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
* is_digit - Verifies if char is digit
* @c: input character
* Return: 1 if c is a digit, otherwise 0
*/
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/**
* convert_size_number - Casts a number  to the specified size
* @num: number to cast
* @size: Number indicating data type
* Return: Number value casted
*/
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
* convert_size_unsgnd - Function to cast number to specified size
* @num: number to cast
* @size: Number indicating data type
* Return: Number value casted
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}






























































