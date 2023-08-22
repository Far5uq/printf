#include <unistd.h>

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
