#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part i:  ALL methods for matrix of type double
int main ( int argc, char * argv[] ) {
// Test 4: det function

  matrix<double> S(2,2);

  S.set(0,0,1.5); S.set(0,1,2.5);
  S.set(1,0,3.5); S.set(1,1,4.5);

    double M = S.det();

    ASSERT(M == -2.0);



}
