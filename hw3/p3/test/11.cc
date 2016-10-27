#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part ii:  ALL methods for matrix of type int
int main ( int argc, char * argv[] ) {
// Test 1: mult function

// M = Q * Q;
  matrix<int> Q(2,2);

  Q.set(0,0,2); Q.set(0,1,4);
  Q.set(1,0,6); Q.set(1,1,8);

  matrix<int> M = Q.mult(Q);

  ASSERT(M.get(0,0) == 28 && M.get(0,1) == 40 && M.get(1,0) == 60 && M.get(1,1) == 88 );


}
