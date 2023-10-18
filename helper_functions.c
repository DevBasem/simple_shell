#include "main.h"

/**
 * string_rev - Reverse the characters in a string.
 * @str: A pointer to the string to be reversed.
 * @len: The length of the string.
 *
 * This function reverses the characters in the given string in-place.
 */
void string_rev(char *str, int len)
{
	int start = 0;
	int end = len - 1;

	if (str == NULL || len <= 0)
	{
		return;
	}

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}

/**
 * _itoa - Convert an integer to a string
 * @n: The integer to convert
 * Return: A string representation of the integer
 */
char *_itoa(int n)
{
	char resultString[20];
	int resultIndex = 0;

	if (n == 0)
		resultString[resultIndex++] = '0';
	else
	{
		while (n > 0)
		{
			resultString[resultIndex++] = (n % 10) + '0';
			n /= 10;
		}
	}
	resultString[resultIndex] = '\0';
	string_rev(resultString, resultIndex);
	return (_strdup(resultString));
}
