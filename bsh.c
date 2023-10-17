#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char** environ;

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

char* custom_fgets(char *str, int size, int fd) {
	char c;
	int i = 0;

	if (str == NULL || size <= 0) {
		errno = EINVAL;
		return NULL;
	}
	while (i < size - 1) {
		int bytesRead = read(fd, &c, 1);

		if (bytesRead < 0) {
			perror("Error reading from file");
			return NULL;
		} else if (bytesRead == 0) {
			if (i == 0) {
				errno = ENOENT;
				return NULL;
			} else {
				break;
			}
		}

		str[i++] = c;

		if (c == '\n') {
			break;
		}
	}

	str[i] = '\0';

	if (i == 0) {
		errno = ENOENT;
		return NULL;
	}

	return str;
}

char* custom_getenv(const char* var) {
	int i;
	if (var == NULL || strlen(var) == 0) {
		errno = EINVAL;
		return NULL;
	}

	for (i = 0; environ[i] != NULL; i++) {
		if (strncmp(environ[i], var, strlen(var)) == 0 && environ[i][strlen(var)] == '=') {
			return environ[i] + strlen(var) + 1;
		}
	}

	return NULL;
}

int execute_command_direct(const char *cmd, char *args[]) {
	if (access(cmd, X_OK) == 0) {
		pid_t pid = fork();

		if (pid == -1) {
			perror("fork");
			_exit(EXIT_FAILURE);
		} else if (pid == 0) {
			if (execve(cmd, args, environ) == -1) {
				perror("execve");
				_exit(127);
			}
		} else {
			int status;
			waitpid(pid, &status, 0);
			return 1;
		}
	}

	return 0;
}

void execute_command_with_path(const char *cmd, char *args[]) {
	char* path_copy;
	char* path_token;
	char* path_env = custom_getenv("PATH");
	if (path_env == NULL || strlen(path_env) == 0) {
		fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
		_exit(127);
	}

	path_copy = strdup(path_env);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL) {
		char full_path[1024];
		snprintf(full_path, sizeof(full_path), "%s/%s", path_token, cmd);
		if (execute_command_direct(full_path, args)) {
			free(path_copy);
			return;
		}

		path_token = strtok(NULL, ":");
	}

	fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
	free(path_copy);
	_exit(127);
}

int main() {
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARG_SIZE];
	char *token;
	int i;

	while (1) {
		if (custom_fgets(input, MAX_INPUT_SIZE, STDIN_FILENO) == NULL) {
			if (errno == ENOENT) {
				break;
			} else {
				perror("custom_fgets");
				_exit(EXIT_FAILURE);
			}
		}

		token = strtok(input, " \t\n\r\f\v");
		if (token != NULL) {
			if (strcmp(token, "exit") == 0) {
				break;
			}

			args[i++] = token;

			while ((token = strtok(NULL, " \t\n\r\f\v")) != NULL) {
				args[i++] = token;
			}

			args[i] = NULL;

			if (!execute_command_direct(args[0], args)) {
				execute_command_with_path(args[0], args);
			}
		}
	}

	return 0;
}
