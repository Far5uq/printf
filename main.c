#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
int characters_printed;
characters_printed = _printf("Hello, %s! The first character of my name is %c.%\n", "ALX", 'F');
printf("Characters printed: %d\n", characters_printed);
return (0);
}
