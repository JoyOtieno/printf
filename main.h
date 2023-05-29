#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

 
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);

#endif
