#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct frmt
{
	char frmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frmt frmt_t - Struct op
 *
 * @frmt: The format.
 * @frm_t: The function associated.
 */
typedef struct frmt frmt_t;

int _printf(const char *format, ...);
int handle_print(const char *frmt, int *i,
va_list args, char buffer[], int flags,
int width, int precision, int size);
void print_buffer(char buffer[], int *buff_inid);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int printCharacter(va_list args, char buffer[], int flags,
		int width, int precision, int size);
int printString(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int printPercent(va_list args, char buffer[],
		int flags, int width, int precision, int size);
/* Functions to print numbers */
int printInteger(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int printBinary(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int printUnsigned(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int printOctal(va_list args, char buffer[],
		int flags, int width, int precision, int size);

int printHexadecimal(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int printHexaUpper(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int printHexa(va_list args, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int printNonPrintable(va_list args, char buffer[],
		int flags, int width, int precision, int size);

/* Funcion to print memory address */
int printPointer(va_list args, char buffer[],
		int flags, int width, int precision, int size);
/*Function to print string in reverse*/
int printReverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);
 /*Function to print a string in rot 13*/
int print_rot13string(va_list arg_l, char buffer[],
	int flags, int width, int precision, int size);



/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *k);
int get_width(const char *format, int *k, va_list args);
int get_precision(const char *format, int *k, va_list args);
int get_size(const char *format, int *k);





/* width handler */
int handlewritechar(char ch, char buffer[],
	int flags, int width, int precision, int size);
int writenumber(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int isprintable(char);
int appendhexacode(char, char[], int);
int is_digit(char);

long int convertsizenumber(long int num, int size);
long int convertsizeunsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

