#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){
    //argv[1], argv[2]

    FILE* _file1 = fopen(argv[1], "r");
    if(!_file1){
        fprintf(stderr, "%s not found\n", argv[1]);
        return 1;
    }

    FILE* _file2 = fopen(argv[2] , "r");
    if(!_file2){
        fprintf(stderr, "%s not found\n", argv[2]);
        fclose(_file1);
        return 1;
    }

    char line[512];
    memset(&line, 0, sizeof(char)*512);
    int c;
    int l_ctr = 0;

    char* _lines[1024];
    memset(&_lines, 0, sizeof(char*)*1024);
    char ctr = 0;
    while((c = fgetc(_file2)) != EOF){
        if(c == '\n'){
            line[l_ctr] = '\0';
            _lines[ctr] = malloc(l_ctr);
            strcpy(_lines[ctr++], line);
            memset(&line, 0, sizeof(char)*512);
            l_ctr = 0;
            continue;
        }
        line[l_ctr++] = c;
    }

    memset(&line, 0, sizeof(char)*512);
    l_ctr = 0;
    char ctr2 = 0;
    while((c = fgetc(_file1)) != EOF){
        if(c == '\n'){
            line[l_ctr] = '\0';
            if(ctr2 <= ctr){
                if(strcmp(line, _lines[ctr2]) != 0)
                    printf("%d: %s\n", ctr2+1, line);
            }else
                break;
            memset(&line, 0, sizeof(char)*512);
            ctr2++;
            l_ctr = 0;
            continue;
        }
        line[l_ctr++] = c;
    }
    fclose(_file1);
    fclose(_file2);
    return 0;
}