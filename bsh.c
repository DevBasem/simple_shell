#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

/**
 * main - Simple UNIX shell
 * Description: Basic UNIX shell that reads and executes single-word commands.
 * Handles errors, including command not found, and Ctrl+D for graceful exit.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[]) 
{
	char input[MAX_INPUT_LENGTH];
	char *args[2];
	char *envp[] = { NULL };
	pid_t child_pid;

	(void)argc;

	while (1)
	{
		printf("%s> ", argv[0]);
		fflush(stdout);
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		input[strcspn(input, "\n")] = '\0';
		args[0] = input;
		args[1] = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execve(args[0], args, envp);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			wait(&status);
		}
	}
	return 0;
}
