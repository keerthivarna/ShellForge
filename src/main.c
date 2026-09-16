#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell.h"
#include "input.h"
#include "parser.h"
#include "process.h"

int main()
{
    char *input;
    char **args;

    printf("=====================================\n");
    printf(" Welcome to %s Version %s\n", SHELL_NAME, SHELL_VERSION);
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");

        input = read_input();

        if (input == NULL)
            break;

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting ShellForge...\n");
            free(input);
            break;
        }

        args = parse_input(input);

        if (args == NULL)
        {
            free(input);
            continue;
        }

        if (args[0] != NULL)
            execute(args);

        free(args);
        free(input);
    }

    return 0;
}
