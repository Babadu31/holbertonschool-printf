#include "main.h"

/**
 * pchar - return char
 * @arg: arg
 * Return: 1 on success
 */
int pchar(va_list arg)
{
putchar(va_arg(arg, int));
return (1);
}
