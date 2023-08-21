#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int (*picker(char ch))(va_list);
int _decimal(va_list arg);
int _char(va_list args);
int _string(va_list args);
int _percent(va_list args);
int _putchar(char c);


#endif
