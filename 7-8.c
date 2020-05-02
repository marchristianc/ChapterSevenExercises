#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPage(FILE *input, FILE *output)
{
    int c;
    int line = 0;
    int page = 1;
    while ((c = fgetc(input)) != EOF)
    {
        fputc(c, output);
        if (c == '\n') {
            line = line + 1;
            if (line == 10)
            {
                fprintf(stdout, "\n\n\t[Page %d]\n\n", page);
                page = page + 1;
                line = 0;
            }
        }

    }
}

int main(int argc, const char *argv[]) {
    FILE *input;
    const char *prog = argv[0];
    while (--argc > 0)
        if ((input = fopen(*++argv, "r")) == NULL) {
            printf("%s not found\n", prog);
            return 1;
        } else {
            printf("\n\n\t[%s]\n\n", *argv);
            printPage(input, stdout);
            fclose(input);
        }
    return 0;
}
