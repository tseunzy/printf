#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int (*pick(char ch))(va_list);
int _char(va_list args);
int _string(va_list args);
int _percent(va_list args);
int myputchar(int x, int count);
int _printf(const char *format, ...);


#endif
