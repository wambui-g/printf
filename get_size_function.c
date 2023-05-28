#include "main.h"

/**
get_size - Calculates the size required for argument casting based on the format specifier.
@format: The formatted string containing the argument.
@i: The index of the current argument.

Return: The calculated size for argument casting.
*/
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
