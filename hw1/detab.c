#include<stdio.h>
#include <stdlib.h> 
#define TAB '\t'
#define space ' '

int main ( int argc, char * argv[] ) {
    FILE * file;
    int val;
    char c;
    int n = 0;
    
    file = fopen(argv[1],"r");
   char * input = argv[2];
    val = atoi(input);
    
        if (!file) {
        printf("File not found\n"); //Detect the existing of file
    }
    else 
    {
        do 
        {
            c = getc(file);
            if (c == TAB)
            {
                while (n < val)
                {
                    putchar(space);
                    n = n+1;
                }
                n=0;
            }
            
            else
            {
            putchar(c);
            }
                 
        }
        while (c !=EOF);
        {
            fclose(file);
       
        }
    }
  return 0;

}