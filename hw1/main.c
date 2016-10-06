#include <stdio.h>
#include "fsm.h"

#define ACCEPT 3
#define REJECT 4
#define NUM_RULES 4

int main ( int argc, char * argv[] ) {
  FILE * file;
    file = fopen(argv[1],"r");
    char ch;
    int i=0 ;
    int linenumber = 0;
    int n = 0;
    char alphabet[100];
    
    
    
     if (!file) {
        printf("File not found\n"); //Detect the existing of file
    }
    else
    {
        
    while((ch = fgetc(file)) != EOF){
      
      if (ch == '\n'){
         linenumber++;
   }
     alphabet[i] = ch;
        i++;
      
   //   if (linenumber = 1)
      
    }
    
    }

  /*
     Example Regular Expression: ab*c
     0 -a-> 1                2 = ACCEPT
     1 -b-> 1                3 = REJECT
     1 -c-> 2
   */

  /* Matrix implementation */
 // int rules[3][NUM_RULES] = {
//    /* x */ { 1,      REJECT, REJECT }, /* In state 0, if you get an 'a', goto state 1 */
 //   /* y */ { REJECT, 1,      REJECT },
//   /* z */ { REJECT, ACCEPT, REJECT }
 // };
  
    int rules[3][NUM_RULES] = {
    /* x */ { 1,      REJECT, ACCEPT, REJECT }, /* In state 0, if you get an 'x', goto state 1 */
    /* y */ { REJECT, ACCEPT,      2, REJECT },
    /* z */ { 2,      REJECT, REJECT, REJECT }
  };

  /* Check the input string */
  char * input = argv[2];
  if ( fsm(alphabet,NUM_RULES,rules,input) == ACCEPT ) {
    printf ( "accept\n");
  } else {
    printf ( "reject\n");
  }
  
    fclose(file);

    return 0;
}
