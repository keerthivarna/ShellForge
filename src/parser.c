#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

char **parse_input(char *input)
{
    char **argv = malloc(MAX_ARGS * sizeof(char *));
    int argc = 0;

    if (argv == NULL)
        return NULL;

    char *token = strtok(input, " ");

    while (token != NULL && argc < MAX_ARGS - 1)
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    argv[argc] = NULL;

    return argv;
}
