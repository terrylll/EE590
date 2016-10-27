#include <iostream>
#include "test.hh"
#include "matrix.hh"

// Part v:  ALL methods for matrix of type complex
int main ( int argc, char * argv[] ) {
// Test 3: scale function
Complexnum a(1,2); //example
Complexnum b(2,3);
Complexnum c(3,4);
Complexnum d(5,6);

matrix<Complexnum> S(2,2);
matrix<Complexnum> Q(2,2);

  S.set(0,0,a); S.set(0,1,b);
  S.set(1,0,c); S.set(1,1,d);


  S.scale(3);
  std::cout << std::endl << S << std::endl;

  // matrix<Complexnum> A = S.add(Q);

  // ASSERT(A.get(1,1) == fraction(5,3));
}
