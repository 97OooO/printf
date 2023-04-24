#ifndef MY_MAIN_H
#define MY_MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define MY_BUFF_SIZE 1024

/* FLAGS */
#define MY_FLAG_MINUS 1
#define MY_FLAG_PLUS 2
#define MY_FLAG_ZERO 4
#define MY_FLAG_HASH 8
#define MY_FLAG_SPACE 16

/* SIZES */
#define MY_SIZE_LONG 2
#define MY_SIZE_SHORT 1

/**
 * struct my_fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated
 */
struct my_fmt
{
	char fmt;
	int (*fn)(va_list, char[],int, int, int, int);
};

/**
 * typedef struct my_fmt my_fmt_t - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated
 */
typedef struct my_fmt my_fmt_t;

int my_printf(const char *format, ...);
int my_handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/****************************** Here the Functions ******************/

/* Functions to print chars and strings */
int my_print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to print numbers */
int my_print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int my_print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

int my_print_hexa(va_list types, char map_to[], char buffer[], int flags,char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int my_print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions to print memory adress */
int my_print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int my_get_flags(const char *format, int *i);
int my_get_width(const char *format, int *i, va_list list);
int my_get_precision(const char *format, int *i, va_list list);
int my_get_size(const char *format, int *i);

/* Function to print string in reverse */
int my_print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int my_print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handler */
int my_handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);



