#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part i:  ALL methods for matrix of type double
int main ( int argc, char * argv[] ) {
// Test 2: Scale function
// S = S * d
  matrix<double> S(2,2);

  S.set(0,0,1.0); S.set(0,1,2.0);
  S.set(1,0,3.0); S.set(1,1,4.0);
  double d = 2.5;
  S.scale(d);
  ASSERT(S.get(0,0) == 2.5 && S.get(0,1) == 5.0 && S.get(1,0) == 7.5 && S.get(1,1) == 10.0);



}
