#include "main.h"

/**
 * execute_cmd - Execute a command with arguments.
 * @command: Array of strings for the command and its arguments.
 * @argv: Array of strings for command's arguments.
 * @index: Index of the command in the input.
 *
 * Executes the specified command, waits for it to complete, and
 * returns its exit status.
 *
 * Return: The exit status of the executed command.
 */
int execute_cmd(char **command, char **argv, int index)
{
	char *fullPath;
	pid_t childPid;
	int status;

	fullPath = get_cmd_path(command[0]);
	if (!fullPath)
	{
		printErrorMessage(argv[0], command[0], index);
		freeStringArray(command);
		return (127);
	}

	childPid = fork();
	if (childPid == 0)
	{
		if (execve(fullPath, command, environ) == -1)
		{
			free(fullPath);
			freeStringArray(command);
		}
	}
	else
	{
		waitpid(childPid, &status, 0);
		freeStringArray(command);
		free(fullPath);
	}

	return (WEXITSTATUS(status));
}
