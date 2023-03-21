#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

define STACK_SIZE 1024

typedef struct {
    int stack[STACK_SIZE];
    int sp; // stack pointer
} Stack;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Stack stack = {0};
    char line[128];
    int line_number = 0;
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#') {
            // skip blank lines and comments
            continue;
        }

        if (strcmp(opcode, "pint") == 0) {
            if (stack.sp == 0) {
                printf("L%d: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
            }
            printf("%d\n", stack.stack[stack.sp - 1]);
        }
        // add support for other opcodes here
        else {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
