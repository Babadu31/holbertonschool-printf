# _printfproject
![Alt Text](https://c.tenor.com/jgUVViyS2CYAAAAC/now-old.gif)

# Summary
## 1-Project presentation
#### General
#### Compilation
#### test file (1)
#### Commande
#### Results
## 2-Requirements
## 3-Question
#### 0.I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
#### 1.Education is when you read the fine print. Experience is what you get if you don't
## 4-Printf
#### example
## 5-_Printf
#### Description of the file structure
#### Quick description of each function by file
### Reminder
#### Structure
#### Prototype
#### example structure va_list
#### Calculation operators
#### Assignment Operators
#### Comparison Operators
#### Logical (Boolean) operators
#### test file char (2)
#### test file char & string (3)
#### test file char & string & percent (4)
## 6-Sources
## 7-Man 
## 8-Tools

# 1-Project presentation

student at holberton school we were offered to create a function similar to printf but would be written. To summarize we must reproduce the same results as printf but with a new function which will be called _printf. first we will explain the conditions for success, then a reminder of the printf function. Finally we will show how we arrived at the expected result for each parameter.


# 2-Requirements

## General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called main.h
- Don’t forget to push your header file
- All your header files should be include guarded
- Note that we will not provide the _putchar function for this project

## Compilation
- Your code will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

### test file (1)
main.c
```
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
```

### Commande
```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```
```
./printf
```
### Results
```
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
```

# 3-Questions
## I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
Write a function that produces output according to a format
- Prototype: int _printf(const char *format, ...);
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the 
following conversion specifiers:
> c

> s

> %
- You don’t have to reproduce the buffer handling of the C library printf function
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

## Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:
> d

> i
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

# 4-printf

The printf function is used to display on the screen window a text that follows a format defined by the programmer. Its general syntax is:
```
printf("format", arg_1, arg_2, ..., arg_n) ;
```
where format represents a character string (placed between quotes "") which contains:

– text to be printed as is;

– format specifications (as many as arg_i parameters ) which indicate how to display the variables arg_1, ..., arg_n provided as parameters. These are format codes .
Each format code begins with the % symbol followed by one (or two) letter(s) indicating the display format of the corresponding arg_i parameter (the one with the same rank in the list of arguments). The value of arg_i will replace its format code when displayed.

The letter placed after the % symbol in the format code indicates the type of parameter associated with the format code (see table on next page). In the previous example, %lf (and its variants like %8.2lf) is the format code associated with a double.

printf parameters can be variables, constants, expressions to be calculated before displaying.

| Format | Type                  | Description                                                                                                                    | Example             |
|--------|-----------------------|--------------------------------------------------------------------------------------------------------------------------------|---------------------|
| %c     | char                  | Smallest addressable unit of a machine, it can contain the basic characters. It is an integer value that can be signed or not. | a G ? +             |
| %c     | signed char           | Signed char type                                                                                                               | [−127; +127]        |
| %c     | unsigned char         | Unsigned char type                                                                                                             | [0; 255]            |
| %s     |                       | String of characters                                                                                                           | Bonjour !           |
| %%     |                       | A % followed by another % character will write a single % to the stream                                                        | %                   |
| %d     | int signed signed int | Standard integer type, signed                                                                                                    | [−32 767 ; +32 767] |
| %X     | signed                | Print an int in hexadecimal                                                                                                    | 9A0F                |
| %i     | int signed signed int | Standard integer type, signed                                                                                                    | [−32 767 ; +32 767] |

## Example
```
/* printf example */
#include <stdio.h>

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}
```
Output:
```
Characters: a A
Decimals: 1977 650000
Preceding with blanks:       1977
Preceding with zeros: 0000001977
Some different radices: 100 64 144 0x64 0144
floats: 3.14 +3e+000 3.141600E+000
Width trick:    10
A string
```

# 5-_printf

## Description of the file structure

| File name    | Description                                    |
|--------------|------------------------------------------------|
| _printf.c    | implements the new _printf.c function          |
| function.c   | print settings                                 |
| get_printf.c | get_printf to get function from function.c     |
| main.c       | file used to test the function to check result |
| main.h       | contains prototypes, libraries and structures  |

## Quick description of each function by file

| File name    | FunctionName | FunctionDescription                        |
|--------------|--------------|--------------------------------------------|
| _printf.c    | _printf      | made the new printf                        |
| function.c   | pchar        | returns a char (print char)                |
| function.c   | pstr         | returns a char (print char)                |
| function.c   | pperc        | returns a percentage (print percent)       |
| get_printf.c | get_printf   | get_printf to get function from function.c |  

## Reminder 

#### Structure
![Alt Text](https://developpement-informatique.com/upload/3214f83949acca18adc584ec75f3505cd7ff9f6c.jpeg)

Each structure type variable has fields marked with unique names. However, the name of the fields is not enough to access them since they only have a context within the structured variable...
To access the fields of a structure, we use the field operator (a simple period) placed between the name of the structured variable that we have defined and the name of the field:
```
Variable_Name.Field_Name;
```

#### Return
In general the 0 is actually used to indicate that the execution of the function took place in the nominal case. Depending on the image set of the function programmers use positive or negative numbers to specify the type of error.
For pointers it's the opposite. You return the pointer when everything is fine and NULL (so 0) when there is an error.

#### Prototype
```
int printf(const char* format, ...);
```
The ... means that it is a variadic function, which can take a variable number of parameters.

format represents, as its name suggests, what the output will be made of (Integer, Double...). Its principle is as follows: each time there is a %, printf looks at the letter following this % and writes the corresponding variable in the parameters. If it's the ith %, printf looks at the (th + 1) parameter.

#### example structure va_list
```
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int addition( int counter, ... ) {

    int sum = 0;
    va_list parametersInfos;
    /* Initialize the va_list structure */
    va_start( parametersInfos, counter );

    /* for all unnamed integer, do an addition */
    while( counter > 0 ) {

        /* Extraction of the next integer */
        sum += (int) va_arg( parametersInfos, int );

        counter --;
    }

    /* Release va_list resources */
    va_end( parametersInfos );

    return sum;
}

int main( int argc, char * argv[] ) {

    int result = addition( 2 /* counter */, 3, 11 );
    printf( "addition( 2, 3, 11 ) == %d\n", result );     /* 14 */


    result = addition( 3 /* counter */, 4, 5, 6 );
    printf( "addition( 3, 4, 5, 6 ) == %d\n", result );   /* 15 */

    return EXIT_SUCCESS;

}
```
output : 
```
addition( 2, 3, 11 ) == 14
addition( 3, 4, 5, 6 ) == 15
```

#### Calculation operators
| Operator |       Denomination      |                   Effect                  | Example | Result (with integer x equal to 7) |
|:--------:|:-----------------------:|:-----------------------------------------:|:-------:|:----------------------------------:|
| +        | addition operator       | Add two values                            | x+3     | 10                                 |
| -        | subtraction operator    | Subtract two values                       | x-3     | 4                                  |
| *        | multiplication operator | Multiplies two values                     | x*3     | 21                                 |
| /        | division operator       | Divides two values                        | x/3     | 2                                  |
| %        | modulo operator         | Returns the remainder of integer division | x%3     | 1                                  |

#### Assignment Operators
| Operator | Effect                                                         |                   Effect                  | Example | Result (with integer x equal to 7) |
|----------|----------------------------------------------------------------|:-----------------------------------------:|:-------:|:----------------------------------:|
| =        | Assigns a value (right) to a variable (left)                   | Add two values                            | x+3     | 10                                 |
| +=       | adds two values and stores the sum in the variable             | Subtract two values                       | x-3     | 4                                  |
| -=       | subtracts two values and stores the difference in the variable | Multiplies two values                     | x*3     | 21                                 |
| *=       | multiplies two values and stores the product in the variable   | Divides two values                        | x/3     | 2                                  |
| /=       | divides two values and stores the quotient in the variable     | Returns the remainder of integer division | x%3     | 1                                  |
| %=       | divides two values and stores the remainder in the variable    |                                           |         |                                    |

#### Comparison Operators
|                       Operator                       |         Denomination        |                           Effect                           | Example |                  Result (with x being 7)                  |
|:----------------------------------------------------:|:---------------------------:|:----------------------------------------------------------:|:-------:|:---------------------------------------------------------:|
| ==  Not to be confused with the assignment sign (=)! | equality operator           | Compare two values and check their equality                | x==3    | Returns 1 if x is equal to 3, otherwise 0                 |
| <                                                    | strict inferiority operator | Checks that a variable is strictly less than a value       | x<3     | Returns 1 if x is less than 3, otherwise 0                |
| <=                                                   | inferiority operator        | Checks that a variable is less than or equal to a value    | x<=3    | Returns 1 if x is less than or equal to 3, otherwise 0    |
| >                                                    | strict superiority operator | Checks that a variable is strictly greater than a value    | x>3     | Returns 1 if x is greater than 3, otherwise 0             |
| >=                                                   | superiority operator        | Checks that a variable is greater than or equal to a value | x>=3    | Returns 1 if x is greater than or equal to 3, otherwise 0 |
| !=                                                   | difference operator         | Checks that a variable is different from a value           | x!=3    | Returns 1 if x is different from 3, otherwise 0           |

#### Logical (Boolean) operators
| Operator |         Denomination        |                                                    Effect                                                    |              Syntax              |                  Result (with x being 7)                  |
|:--------:|:---------------------------:|:------------------------------------------------------------------------------------------------------------:|:--------------------------------:|:---------------------------------------------------------:|
| \|\|     | logical OR                  | Verifies that one of the conditions is fulfilled                                                             | ((condition1) \|\| (condition2)) | Returns 1 if x is equal to 3, otherwise 0                 |
| &&       | logical AND                 | Check that all conditions are met                                                                            | ((condition1) && (condition2))   | Returns 1 if x is less than 3, otherwise 0                |
| !        | logical NOT                 | Inverts the state of a boolean variable (returns the value 1 if the variable is worth 0, 0 if it is worth 1) | !(condition)                     | Returns 1 if x is less than or equal to 3, otherwise 0    |
| >        | strict superiority operator | Checks that a variable is strictly greater than a value                                                      | x>3                              | Returns 1 if x is greater than 3, otherwise 0             |
| >=       | superiority operator        | Checks that a variable is greater than or equal to a value                                                   | x>=3                             | Returns 1 if x is greater than or equal to 3, otherwise 0 |
| !=       | difference operator         | Checks that a variable is different from a value                                                             | x!=3                             | Returns 1 if x is different from 3, otherwise 0           |


## test file char (2)

```
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

_printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
}
```

## test file char & string (3)

```
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

_printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
  _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
}
```

## test file char & string & percent (4)

``` 
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

_printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
  _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
      len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
}
```

# 6-Sources

* Secrets of printf (pdf)
https://www.cypress.com/file/54761/download

* Flowcharts and diagram (organigrammes et diagrammes)

* Display using the printf function
https://public.iutenligne.net/informatique/algorithme-et-programmation/priou/LangageC/61_affichage__laide_de_la_fonction_printf.html

* printf
https://cplusplus.com/reference/cstdio/printf/?kw=printf

* fprintf, printf and sprintf functions
https://koor.fr/C/cstdio/fprintf.wp

* Format Specification Syntax: printfwprintf Functions
https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170

# 7-man

* printf
https://man7.org/linux/man-pages/man3/printf.3.html

* write
https://man7.org/linux/man-pages/man2/write.2.html

* malloc
https://man7.org/linux/man-pages/man3/malloc.3.html

* free
https://linux.die.net/man/3/free

* va_start
https://www.tutorialspoint.com/c_standard_library/c_macro_va_start.htm

* va_end
https://linux.die.net/man/3/va_end

* va_copy
https://linux.die.net/man/3/va_copy

* va_arg
https://linux.die.net/man/3/va_arg

* return
https://docs.microsoft.com/fr-fr/cpp/c-language/return-statement-c?view=msvc-170

* continue
https://docs.microsoft.com/fr-fr/cpp/c-language/continue-statement-c?view=msvc-170

* operators
https://www.programiz.com/c-programming/c-operators

* strlen
https://koor.fr/C/cstring/strlen.wp


# 8-Tools

* Replit (testing machine)
https://replit.com/

* Pythontutor (decomposing machine)
https://pythontutor.com/



![Alt Text](https://c.tenor.com/pagVxAkHfWAAAAAC/my-job-here-is-done-bye.gif)



sources mandatory + advanced without getting caught by the school : https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab


authors : MISSUD Bastien & BELKHIRI Myriam
