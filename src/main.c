#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "input.h"

int main()
{
    char *input;

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

        printf("You entered : %s\n", input);

        free(input);
    }

    return 0;
}
