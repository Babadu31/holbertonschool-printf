#include "main.h"

/**
 * pchar - return char
 * @arg: argument
 * Return: 1 on success
 */

int pchar(va_list arg)
{
  putchar(va_arg(arg, int));
  return (1);
}

/**
 * pstr - return an str
 * @arg: var to write
 * Return: string
 */
int pstr(va_list arg)
{
  int x = 0;
  char *s = va_arg(arg, char *);

  if (s == NULL)
    s = "(null)";
  while (s[x] != '\0')
    {
      putchar(s[x]);
      x++;
    }
  return (x);
}

/**
 * pperc - return per
 * @arg: arg
 * Return: per
 */
int pperc(va_list arg)
{
  (void)arg;
  putchar('%');
  return (1);
}
