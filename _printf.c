#include "main.h"

/**
 * _printf - new printf
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{

int x = 0;
int y = 0;
int z = 0;
va_list valst;

if (format == NULL || (strlen(format) == 1 && format[0] == '%'))
{
return (-1);
}
va_start(valst, format);
while (format && format[x])
{
if (format[x] != '%')
{
putchar(format[x]);
y++;
}
if (format[x] == '%' && format[x + 1] != 'K' && format[x + 1] != '!')
{
z = get_printf(*(format + (x + 1)), valst);
if (z != 0)
y = y + z;
x = x + 2;
continue;
if (*(format + (x + 1)) == '\0')
{
putchar(format[x]);
y++;
}
}
else if ((format[x] == '%' && format[x + 1] == 'K') ||
(format[x] == '%' && format[x + 1] == '!'))
{
putchar(format[x]);
y++;
}
x++;
}
va_end(valst);
return (y);
}
