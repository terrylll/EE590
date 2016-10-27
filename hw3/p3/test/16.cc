#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part ii:  ALL methods for matrix of type int
int main ( int argc, char * argv[] ) {
// Test 6: Less than function

  matrix<double> S(2,2);
  matrix<double> Q(2,2);

  S.set(0,0,1); S.set(0,1,2);
  S.set(1,0,3); S.set(1,1,4);

  Q.set(0,0,5); Q.set(0,1,6);
  Q.set(1,0,7); Q.set(1,1,8);

  if (S.less_than(Q)){
    SUCCEED;
  }else {
    FAIL;
  }

}
