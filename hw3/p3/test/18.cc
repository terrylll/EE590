#include <iostream>
#include "test.hh"
#include "matrix.hh"

// Part iii:  ALL methods for matrix of type bool
int main ( int argc, char * argv[] ) {
// Test 1: Mult function
  matrix<bool> Q(2,2), P(2,2);

  Q.set(0,0,true); Q.set(0,1,false);
  Q.set(1,0,false); Q.set(1,1,true);

  P.set(0,0,true); P.set(0,1,false);
  P.set(1,0,true); P.set(1,1,false);

  matrix<bool> M = Q.mult(P);

  std::cout << std::boolalpha;
  std::cout << std::endl << M << std::endl;

  return 0;

}
