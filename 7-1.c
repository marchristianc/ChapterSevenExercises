#include <stdio.h>
#include <ctype.h>
#include <string.h>


//usage: ./upper file == uppercase
//usage: ./anything_else file == lowercase
int main(int argc, const char* argv[]){
    int upper = 0;
    if(strstr(argv[0], "upper"))
        upper = 1;
    //1 if uppercase, 0 if lowercase

    char c;
    while((c = fgetc(stdin)) != EOF)
        fputc(upper ? toupper(c) : tolower(c), stdout);
    printf("\n");
    return 0;
}