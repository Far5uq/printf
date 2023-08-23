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
characters_printed = _printf("Hello, %s! My favorite character is %c.%%\n",
"Alice", 'A');
printf("Characters printed: %d\n", characters_printed);
return (0);
}
