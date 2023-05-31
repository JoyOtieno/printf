#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int get_flags(const char *format, int *t);
int get_width(const char *format, int *t, va_list nums);
int get_precision(const char *format, int *t, va_list nums);
int get_size(const char *format, int *t);

#define UNUSED(x) (void) (x)
#define BSIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_SHORT 1
#define S_LONG 2

/**
*struct fmt - Struct op
*
*@fn: The associated function
*@fmt: The format
*/
struct fmt
{
	char fmt;
	int(*fn)(va_list, char[], int, int, int, int);
};

/**
*typedef struct fmt fmt_t - Struct op
*@fmt: The format
*@fn: The associated function
*/
typedef struct fmt fmt_t;

int _printf (const char *format, ...);
int handle_print(const char *fmt, int *t, va_list nums, char buffer[],
int flags, int width, int precision, int size);


int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list nums,
char buffer[], int flags, int width, int precision, int size);

int print_char(va_list types, char buffer[], int flags, int width,
int precision, int size);

int print_percent(va_list types, char buffer[], int flags, int width,
int precision, int size);

int print_int(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[], int flags, int width,
int precision, int size);

int print_pointer(va_list types, char buffer[], int flags, int width,
int precision, int size);

int print_reverse(va_list types, char buffer[], int flags, int width,
int precision, int size);

int print_rot13string(va_list types, char buffer[], int flags, int width,
int precision, int size);

int handle_write_char(char c, char buffer[], int flags, int width,
int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width,
int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags,
char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width,
int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


int print_string(va_list nums, char buffer[],
int precision, int flags, int width, int size)
#endif
