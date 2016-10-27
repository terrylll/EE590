#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part ii:  ALL methods for matrix of type int
int main ( int argc, char * argv[] ) {
// Test 4: det function

  matrix<int> S(2,2);

  S.set(0,0,2); S.set(0,1,4);
  S.set(1,0,6); S.set(1,1,8);

    double M = S.det();

    ASSERT(M == -8);



}
