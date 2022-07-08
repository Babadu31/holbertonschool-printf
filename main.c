#include "main.h"

/**
 * print-char - 
 *
 */
int print_char(va_list args)
{
int c;

c = va_arg(args, int);

return (write(1, &c, 1));
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
