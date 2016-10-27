#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part ii:  ALL methods for matrix of type int
int main ( int argc, char * argv[] ) {
// Test 7: equals function

  matrix<int> S(2,2);
  matrix<int> Q(2,2);

  S.set(0,0,1); S.set(0,1,2);
  S.set(1,0,3); S.set(1,1,4);

  Q.set(0,0,1); Q.set(0,1,2);
  Q.set(1,0,3); Q.set(1,1,4);

  if (Q.equals(S)){
    SUCCEED;
  }else {
    FAIL;
  }


}
