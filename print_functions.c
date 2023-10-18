#include "main.h"

/**
 * printErrorMessage - Print error message.
 * @name: Program name
 * @cmd: Command not found
 * @e_index: Error index
 *
 * Prints an error message to stderr when a command is not found.
 * Returns the error message.
 */
void printErrorMessage(char *name, char *cmd, int e_index)
{
	char *indexStr, errorMsg[] = ": not found\n";

	indexStr = _itoa(e_index);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indexStr, _strlen(indexStr));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, errorMsg, _strlen(errorMsg));
	free(indexStr);
}

/**
 * print_environment - Prints the system's environment variables.
 *
 * This function displays the environment variables of the system,
 * excluding the "$" symbol before each variable.
 */
void print_environment(void)
{
	int index = 0;

	while (environ[index])
	{
		_putchar(environ[index]);
		_putchar("\n");
		index++;
	}
}
