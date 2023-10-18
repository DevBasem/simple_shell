#include "main.h"

/**
 * _strdup - Duplicate a string.
 * @str: The input string to duplicate.
 * Return: A pointer to the newly allocated duplicate string,
 * or NULL if it fails.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	int i, length;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: Integer value indicating their relationship
 */
int _strcmp(char *s1, char *s2)
{
	int result = (int)*s1 - (int)*s2;

	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		result = (int)*s1 - (int)*s2;
	}
	return (result);
}

/**
 * _strlen - Calculate the length of a null-terminated string.
 *
 * @s: A pointer to the null-terminated string to be measured.
 *
 * Return: The length of the string (excluding the null-terminator '\0').
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strcat - Concatenate two strings.
 *
 * Appends the `src` string to the end of the `dest` string.
 *
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string to append.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;

	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}

	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}

	*dest_ptr = '\0';

	return (dest);
}

/**
 * _strcpy - Copy a string from source to destination.
 * @dest: Destination string where the copy will be stored.
 * @src: Source string to be copied.
 *
 * Return: A pointer to the beginning of the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
