#include <stdio.h>
#include <stdlib.h>
#include "input.h"

char *read_input(void)
{
    char *buffer = NULL;
    size_t size = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        char *temp = realloc(buffer, size + 2);

        if (temp == NULL)
        {
            free(buffer);
            return NULL;
        }

        buffer = temp;
        buffer[size++] = (char)c;
        buffer[size] = '\0';
    }

    return buffer;
}
