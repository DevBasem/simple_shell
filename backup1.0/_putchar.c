#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes a string to stdout
 * @c: The string to print
 *
 */
void _putchar(const char *c)
{
	write(STDOUT_FILENO, c, _strlen(c));
}
