#include <iostream>
#include "test.hh"
#include "matrix.hh"

// Part iv:  ALL methods for matrix of type fraction
int main ( int argc, char * argv[] ) {
// Test 7: Less than function
fraction a(1,2); //example
fraction b(2,3);
fraction c(3,4);
fraction d(5,6);
fraction e(6,7);

  matrix<fraction> S(2,2);
  matrix<fraction> Q(2,2);
  S.set(0,0,a); S.set(0,1,c);
  S.set(1,0,b); S.set(1,1,d);

  Q.set(0,0,1); Q.set(0,1,1);
  Q.set(1,0,1); Q.set(1,1,1);


  if (S.less_than(Q)){
    SUCCEED;
  }else {
    FAIL;
  }
}
