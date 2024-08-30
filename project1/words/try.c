#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048

int main() {
    FILE *file = fopen("animals.txt", "r");  // Open the file in read modeq

    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file)) 
    {
        char *token = strtok(line, ", ");
        while (token) 
        {
            printf("%s\n", token);
            token = strtok(NULL, ", ");
        }
    }

    fclose(file);
    return 0;
}

