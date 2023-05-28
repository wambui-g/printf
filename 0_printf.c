#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int print_int(int num);
int print_uint(unsigned int num);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int uppercase);

/**
 * _printf- printf function
 * @format: constant string pointer
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0, num;
	char ch, *str;
	unsigned int uint_num;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				case 's':
					str = va_arg(args, char*);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
