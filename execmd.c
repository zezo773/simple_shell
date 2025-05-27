#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

extern char **environ;

void execmd(char **argv)
{
    char *command = NULL, *actual_command = NULL;
    pid_t pid;
    int status;

    if (argv)
    {
        command = argv[0];
        actual_command = get_location(command);

        if (actual_command == NULL)
        {
            fprintf(stderr, "Command not found: %s\n", command);
            return;
        }

        pid = fork();
        if (pid == 0)
        {

            if (execve(actual_command, argv, environ) == -1)
            {
                perror("Error:");
                free(actual_command);
                exit(EXIT_FAILURE);
            }
        }
        else if (pid > 0)
        {
            waitpid(pid, &status, 0);
            free(actual_command);
        }
        else
        {
            perror("fork failed");
            free(actual_command);
        }
    }
}

