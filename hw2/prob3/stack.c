#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
     FILE * file;
     FILE * refile;

    		char buf[100];
        int j = 0;
        int x = 0;
        int count = 0;

    		file =fopen(argv[1],"r+");

    		if (!file)
        		  printf("File not found\n");

    char **strings = (char**)malloc(100*sizeof(char*));
    char **temp = (char**)malloc(100*sizeof(char*));

    int i = 0;

    while (fgets(buf, 100, file) != NULL) {

    strings[j] = (char*)malloc(60*sizeof(char));
    sprintf(strings[j],"%s", buf);
    j++ ;
}

    if (strcmp(argv[2] ,"pop") == 0){
      refile = fopen(argv[1],"w+");
      for (count = 1; count < j;  count++ ) {

      fprintf(refile, "%s",strings[count]);
      printf("%s",strings[count]);
      }
    }
    else if ((strcmp(argv[2] ,"print_top") == 0)){
      printf("%s",strings[0]);
    }
    else if ((strcmp(argv[2] ,"swap_top") == 0)){

      if (strings[2] != NULL) {
      temp[0] = (char*)malloc(60*sizeof(char));
      refile = fopen(argv[1],"w+");
      temp[0] = strings[1];
      strings[1] = strings[0];
      strings[0] = temp[0];

      for (count = 0; count < j;  count++ ) {
      fprintf(refile, "%s",strings[count]);
      printf("%s",strings[count]);
    }
  }
  else {
    for (count = 0; count < j;  count++ ) {
    printf("%s",strings[count]);
        }
      }
    }
    else {
      printf("Wrong Command!\n");
    }

    for(i = 0; i < j; i++){
        free(strings[i]);
    }
    free(strings);
    free(temp);

    fclose(file);
    return 0;
}
