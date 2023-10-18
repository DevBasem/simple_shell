#include "main.h"

/**
 * main - Main function for a simple shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: The exit status of the shell.
 */
int main(int argc, char **argv)
{
	char *user_input = NULL;
	char **command_args;
	int exit_status = 0, command_index = 0;
	(void) argc;

	while (1)
	{
		user_input = get_cmd();
		if (user_input == NULL)
		{
			if (isatty(STDIN_FILENO))
				_putchar("\n");
			return (exit_status);
		}
		command_index++;
		command_args = split_input(user_input);
		if (!command_args)
			continue;
		if (_strcmp(command_args[0], "exit") == 0)
		{
			freeStringArray(command_args);
			return (exit_status);
		}
		else if (_strcmp(command_args[0], "env") == 0)
		{
			print_environment();
			freeStringArray(command_args);
		}
		else
			exit_status = execute_cmd(command_args, argv, command_index);
	}
}
