#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part i:  ALL methods for matrix of type double
int main ( int argc, char * argv[] ) {
// Test 6: Less than function

  matrix<double> S(2,2);
  matrix<double> Q(2,2);

  S.set(0,0,1.0); S.set(0,1,2.0);
  S.set(1,0,3.0); S.set(1,1,4.0);

  Q.set(0,0,5.0); Q.set(0,1,6.0);
  Q.set(1,0,7.0); Q.set(1,1,8.0);

  try {
     S.less_than(Q);
     SUCCEED;
  } catch ( matrix_exception &e ) {
    FAIL;
  }


}
