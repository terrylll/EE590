#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrix_add ( Matrix * A, Matrix * B ) {

  ASSERT ( A->rows == B->rows && A->columns == B->columns );

  Matrix * C = matrix_new ( A->rows, A->columns );

  for ( int i=0; i<A->rows; i++ ) {
    for ( int j=0; j<A->columns; j++ ) {
      matrix_set(C, i, j, matrix_get(A,i,j) + matrix_get(B,i,j) );
    }
  }

  return C;

}

int matrix_equal (Matrix * A, Matrix * B) {
int com = 1;
//ASSERT ( A->rows == B->rows && A->columns == B->columns );
for ( int i=0; i<A->rows; i++ ) {
  for ( int j=0; j<A->columns; j++ ) {
    if (matrix_get(A,i,j) != matrix_get(B,i,j)){
      com = 0;
      break;
    }
  }
}
  if (com == 1)
    return 1;
  else
    return 0;
}

Matrix * matrix_identity (int n) {

Matrix * D = matrix_new ( n, n );

for ( int i = 0; i<n; i++){
  for (int j=0; j<n; j++){
    if (i == j){
      matrix_set(D, i, j, 1);
    }
    else {
      matrix_set(D, i, j, 0);
    }
  }
}

return D;

}

Matrix * matrix_scale(Matrix * M, double s) {

  Matrix * E = matrix_new ( M->rows, M->columns );

  for ( int i=0; i<M->rows; i++ ) {
    for ( int j=0; j<M->columns; j++ ) {
      matrix_set(E, i, j, matrix_get(M,i,j) * s);
    }
  }

  return E;
}

Matrix * matrix_transpose ( Matrix * M ){

  Matrix * F = matrix_new ( M->columns, M->rows );

  for ( int i=0; i<M->columns; i++ ) {
    for ( int j=0; j<M->rows; j++ ) {
      matrix_set(F, i, j, matrix_get(M,j,i));
    }
  }
  return F;
}

Matrix * matrix_mult ( Matrix * A, Matrix * B ) {
  double sum = 0;

  Matrix * G = matrix_new ( A->rows, B->columns );

  for ( int i=0; i<A->rows; i++ ) {
    for ( int j=0; j<B->columns; j++ ) {
      for ( int k=0; k<B->rows; k++ ){
            sum = sum + (matrix_get(A,i,k) * matrix_get(B,k,j));
      }
      matrix_set(G, i, j, sum);
      sum = 0;
    }
  }
    return G;
}

Matrix * matrix_power ( Matrix * M, int n ) {

  ASSERT ( M->rows == M->columns );

  Matrix * mult = matrix_new ( M->rows, M->columns );
  Matrix * H = matrix_new ( M->rows, M->columns );

//  for ( int i=0; i<M->rows; i++ ) {
//    for ( int j=0; j<M->columns; j++ ) {
if (n == 1){
  for ( int i=0; i<M->rows; i++ ) {
    for ( int j=0; j<M->columns; j++ ) {
      matrix_set(mult, i, j, matrix_get(M,i,j));
    }
  }
}
else {
  mult = matrix_mult(M,M);
      for ( int k=0; k<n-2; k++ ){
          mult = matrix_mult(mult,M);
        }
      }
        return mult;

}

Matrix * matrix_minor ( Matrix * M, int n ) {

  ASSERT ( 0 <= n && n < M->columns );

  Matrix * P = matrix_new ( M->rows - 1, M->columns - 1 );

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=0; j<n; j++ ) {
      matrix_set(P,i-1,j,matrix_get(M,i,j));
    }
  }

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=n+1; j<M->columns; j++ ) {
      matrix_set(P,i-1,j-1,matrix_get(M,i,j));
    }
  }

  return P;

}

Matrix * cofactor (Matrix * M) {

  ASSERT ( M->rows == M->columns );

Matrix * Q = matrix_new ( M->rows - 1, M->columns - 1 );
Matrix * R = matrix_new ( M->rows , M->columns);
double sign = 1;
int f = M->rows;

  for (int q = 0; q<f; q++) {
    for (int p = 0; p<f; p++){
      int m = 0;
      int n = 0;
      for(int i = 0; i<f; i++) {
        for(int j = 0; j<f; j++) {
          if (i != q && j != p) {
            matrix_set(Q,m,n,matrix_get(M,i,j));
            if (n < (f-2)){
              n++;
            }
            else {
              n = 0;
              m++;
            }
          }
        }
      }
      matrix_set(R,q,p, matrix_det(Q) * sign);
      sign *= -1 ;
    }
  }
  return R;
}

Matrix * matrix_inverse (Matrix * M){
  ASSERT ( M->rows == M->columns && matrix_det(M) !=0 );
  double det = 0;

Matrix * S = matrix_new ( M->rows , M->columns);
Matrix * T = matrix_new ( M->rows , M->columns);




  det = 1 / matrix_det(M);
  T =  matrix_transpose(cofactor(M));

  for ( int i=0; i<M->rows; i++ ) {
    for ( int j=0; j<M->columns; j++ ) {
      matrix_set(S, i, j, det * matrix_get(T,i,j) );
      }
    }

  return S;
  }


double matrix_det ( Matrix * M ) {

  if ( M->rows == 1 && M->columns == 1 ) {

    return matrix_get(M,0,0);

  } else {

    double sign = 1,
           sum = 0;

    for ( int i=0; i<M->columns; i++ ) {
      Matrix * P = matrix_minor ( M, i );
      sum += sign * matrix_get(M,0,i) * matrix_det(P);
      sign *= -1;
      matrix_destroy ( P );
    }

    return sum;

  }


}
