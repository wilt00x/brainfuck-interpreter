#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE 30000

unsigned char tapes[MEMSIZE] = {0};
unsigned char *bytes_pointer = &tapes;

void compile_instructions(void)
{
    int i;
    
    for(i=0;i<sizeof(tapes);i++)
    {   
        switch(tapes[i])
        {
            case '<':
                --bytes_pointer;
                continue;
            case '>':
                ++bytes_pointer;
                continue;
            case '-':
                --*bytes_pointer;
                continue;
            case '+':
                ++*bytes_pointer;
                continue;
            case '.':
                putchar(*bytes_pointer);
                continue;
            case ',':
                *bytes_pointer = getchar();
                continue;
            case '[':
                while(*bytes_pointer != ']')
                {
                    bytes_pointer++;
                }
            case ']':
                while(*bytes_pointer != '[')
                {
                    bytes_pointer--;
                }
            default:
                break;
        }
    }
}

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    
    if(argc != 2)
        exit(1);
        
    if(sizeof(argv)>MEMSIZE)
    {
        printf("[exit]: string > 30000 bytes\n");
        exit(1);
    }
    strncpy(tapes, argv[1], sizeof(argv[1]));

    compile_instructions();
}
