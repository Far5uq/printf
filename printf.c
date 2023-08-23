#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - A custom putchar function
 * @c: The character to be printed
 *
 * Return: The number of characters printed (always 1)
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_char - Print a character to stdout.
 * @args: The va_list containing the character to print.
 *
 * Return: The number of characters printed.
 */

int print_char(va_list args)
{
char c;
c = va_arg(args, int);
return (write(1, &c, 1));
}

/**
 * print_string - Print a string to stdout.
 * @args: The va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list args)
{
char *s;
int count = 0;
s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
while (*s)
{
write(1, s, 1);
s++;
count++;
}
return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
count++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == 'c')
count += print_char(args);
else if (*format == 's')
count += print_string(args);
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
else
{
write(1, format - 1, 2);
count += 2;
}
}
format++;
}
va_end(args);
return (count);
}
