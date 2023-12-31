#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * print_char - Print a single character
 * @args: The va_list containing the character to print
 *
 * Return: The number of characters printed (always 1)
 */
int print_char(va_list args)
{
return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Print a string
 * @args: The va_list containing the string to print
 *
 * Return: The number of characters printed
 */

int print_string(va_list args)
{
char *str;
int count;
str = va_arg(args, char *);
count = 0;
if (str == NULL)
str = "(null)";
while (*str)
{
_putchar(*str);
str++;
count++;
}
return (count);
}

/**
 * print_int - Print an integer
 * @args: The va_list containing the integer to print
 *
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
int n;
int count;
n = va_arg(args, int);
count = 0;
if (n < 0)
{
_putchar('-');
count++;
n = -n;
}
if (n / 10 != 0)
count += print_int(args);
_putchar((n % 10) + '0');
return (count + 1);
}

/**
 * _printf - Custom printf function with limited format specifiers
 * @format: The format string to be printed
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int count;
count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
_putchar('%');
count++;
break;
default:
_putchar('%');
_putchar(*format);
count += 2;
break;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
