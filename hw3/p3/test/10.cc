#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part i:  ALL methods for matrix of type double
int main ( int argc, char * argv[] ) {
// Test 7: equals function

  matrix<double> S(2,2);
  matrix<double> Q(2,2);

  S.set(0,0,1.0); S.set(0,1,2.0);
  S.set(1,0,3.0); S.set(1,1,4.0);

  Q.set(0,0,1.0); Q.set(0,1,2.0);
  Q.set(1,0,3.0); Q.set(1,1,4.0);

  try {
     S.equals(Q);
     SUCCEED;
  } catch ( matrix_exception &e ) {
    FAIL;
  }


}
