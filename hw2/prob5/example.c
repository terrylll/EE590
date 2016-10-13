#include <stdio.h>
#include "matrix.h"

int main ( int argc, char * argv[] ) {

  Matrix * A = matrix_new ( 3, 3 ),
         * B = matrix_random ( 4, 4 ),
         * C;


  matrix_set ( A, 0, 0, 1 ); matrix_set ( A, 0, 1, 2 ); matrix_set ( A, 0, 2, 3 );
  matrix_set ( A, 1, 0, 0 ); matrix_set ( A, 1, 1, 4 ); matrix_set ( A, 1, 2, 5 );
  matrix_set ( A, 2, 0, 1 ); matrix_set ( A, 2, 1, 0 ); matrix_set ( A, 2, 2, 6 );

/* Equal */
  printf("Equality = %d\n",matrix_equal(A,A));

/* Identity */
   C = matrix_identity(3);
   matrix_print(C); NL;
   matrix_destroy(C);

/* Scale */
   C = matrix_scale(A, 3);
   matrix_print (C); NL;
   matrix_destroy(C);

/* Transpose */
   C = matrix_transpose(A);
   matrix_print (C); NL;
   matrix_destroy(C);

/* Multiplication */
   C = matrix_mult(A,A);
   matrix_print (C); NL;
   matrix_destroy(C);

/* Power */
   C = matrix_power(A,3);
   matrix_print (C); NL;
   matrix_destroy(C);

/* Inverse */
   C = matrix_inverse(A);
   matrix_print (C); NL;
   matrix_destroy(C);

  return 0;

}
