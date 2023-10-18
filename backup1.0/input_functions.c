#include "main.h"

/**
 * freeStringArray - Frees a dynamically allocated string array
 * @array: The string array to be freed
 *
 * This function frees the memory allocated for each string in the input array
 * and then frees the array itself.
 */
void freeStringArray(char **array)
{
	int index;

	if (!array)
		return;

	for (index = 0; array[index]; index++)
	{
		free(array[index]);
		array[index] = NULL;
	}

	free(array);
}

/**
 * split_input - Splits the input command line into an array of strings.
 * @input_command: The input command line to split.
 *
 * Return: An array of strings containing the tokens, or NULL on failure.
 */
char **split_input(char *input_command)
{
	char *buffer = NULL, *token = NULL;
	char **token_array = NULL;
	int token_count = 0;
	int i;

	if (!input_command)
		return (NULL);
	buffer = _strdup(input_command);
	token = strtok(buffer, " \t\n");
	if (token == NULL)
	{
		free(input_command);
		free(buffer);
		return (NULL);
	}
	while (token)
	{
		token_count++;
		token = strtok(NULL, " \t\n");
	}
	free(buffer);
	token_array = malloc(sizeof(char *) * (token_count + 1));
	if (!token_array)
	{
		free(input_command);
		return (NULL);
	}
	token = strtok(input_command, " \t\n");
	i = 0;
	while (token)
	{
		token_array[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(input_command);
	token_array[token_count] = NULL;
	return (token_array);
}
