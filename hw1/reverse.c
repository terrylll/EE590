#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
     
    int count,i = 0;
     
    file = fopen(argv[1],"r");
    
    if (!file) {
        printf("File not found\n"); //Detect the existing of file
    }
    else {
    fseek(file,0,SEEK_END); // Find the position from the begin to the end
    count = ftell(file);
     
    while( i < count )
    {
        fseek(file,-i,SEEK_END);
        printf("%c",fgetc(file));
        i++;
    }
    }
    fclose(file);
     
    return 0;
}
