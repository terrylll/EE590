#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part i:  ALL methods for matrix of type double
int main ( int argc, char * argv[] ) {
// Test 1: Mult function
// M = Q * Q;
  matrix<double> Q(2,2);

  Q.set(0,0,1.5); Q.set(0,1,2.5);
  Q.set(1,0,3.5); Q.set(1,1,4.5);

  matrix<double> M = Q.mult(Q);

  ASSERT(M.get(0,0) == 11.0 && M.get(0,1) == 15.0 && M.get(1,0) == 21.0 && M.get(1,1) == 29.0 );



}
