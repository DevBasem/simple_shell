#include "main.h"

/**
 * get_cmd - Read and return a command from input.
 * Return: A dynamically allocated string representing
 * the user's command or Returns NULL on error or empty input.
 */
char *get_cmd(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t read_result;

	if (isatty(STDIN_FILENO))
		printf("#Basem_Shell$ ");

	read_result = getline(&command, &command_size, stdin);

	if (read_result == -1)
	{
		free(command);
		return (NULL);
	}

	return (command);
}

/**
 * get_cmd_path - Get the full path of an input command.
 * @command: The command for which to find the path.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *get_cmd_path(char *command)
{
	int i;
	char *path_var;
	char *token;
	char *full_path;
	struct stat file_stat;

	for (i = 0; command[i] ; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &file_stat) == 0)
				return (strdup(command));
			return (NULL);
		}
	}

	path_var = _getenv("PATH");
	if (!path_var)
		return (NULL);

	token = strtok(path_var, ":");
	while (token)
	{
		full_path = malloc(_strlen(token) + _strlen(command) + 2);
		if (full_path)
		{
			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			if (stat(full_path, &file_stat) == 0)
			{
				free(path_var);
				return (full_path);
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
	}
	free(path_var);
	return (NULL);
}

/**
 * _getenv - Get the value of an environment variable.
 * @variable_name: The name of the environment variable to retrieve.
 * Return: The value of the specified environment variable,
 * or NULL if not found.
 */

char *_getenv(char *variable_name)
{
	int i;
	char *current_environment_entry;
	char *env_key;
	char *env_value;
	char *result;

	for (i = 0; environ[i]; i++)
	{
		current_environment_entry = _strdup(environ[i]);
		env_key = strtok(current_environment_entry, "=");

		if (_strcmp(env_key, variable_name) == 0)
		{
			env_value = strtok(NULL, "\n");
			result = _strdup(env_value);
			free(current_environment_entry);
			return (result);
		}

		free(current_environment_entry);
	}
	return (NULL);
}
