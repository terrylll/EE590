#include <iostream>
#include "test.hh"
#include "matrix.hh"

// Part v:  ALL methods for matrix of type complex
int main ( int argc, char * argv[] ) {
// Test 7: less than function
Complexnum a(1,2); //example
Complexnum b(2,3);
Complexnum c(3,4);
Complexnum d(5,6);
Complexnum e(9,9);
matrix<Complexnum> S(2,2);
matrix<Complexnum> Q(2,2);

  S.set(0,0,a); S.set(0,1,b);
  S.set(1,0,c); S.set(1,1,d);

  Q.set(0,0,e); Q.set(0,1,e);
  Q.set(1,0,e); Q.set(1,1,e);

  if (S.less_than(Q)){
    SUCCEED;
  }else {
    FAIL;
  }


  // matrix<Complexnum> A = S.add(Q);

  // ASSERT(A.get(1,1) == fraction(5,3));
}
