#include "main.h"

/**
 * get_printf - get_printf to get function from function.c
 * @ap: arguments
 * @c: char
 * Return: char
 */

int get_printf(const char c, va_list ap)
{
int x = 0;
int y = 0;
print_t type[] = {
{'c', pchar},
{'s', pstr},
{'%', pperc},
};
while (type[x].t != 0)
{
if (type[x].t == c)
{
y += type[x].f(ap);
return (y);
}
x++;
}
return (0);
}
