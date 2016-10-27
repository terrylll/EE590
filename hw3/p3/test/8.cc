#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part i:  ALL methods for matrix of type double
int main ( int argc, char * argv[] ) {
// Test 5: inverse function

  matrix<double> S(2,2);

  S.set(0,0,1.0); S.set(0,1,2.0);
  S.set(1,0,3.0); S.set(1,1,4.0);

    matrix<double> M = S.inverse();

    ASSERT(M.get(0,0) == -2 && M.get(0,1) == 1 && M.get(1,0) == 1.5 && M.get(1,1) == -0.5);



}
