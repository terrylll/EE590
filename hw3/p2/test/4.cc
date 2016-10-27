#include "test.hh"
#include "Complexnum.hh"

// Part iv: The conjugate (should return a new complex number).
int main ( ) {

  // Test 1: 
  Complexnum a(3,4);
  Complexnum x;

  x = conjugate(a);

  cout <<"\n"<< x << endl;
  ASSERT(x.r == 3 && x.i == -4);
  SUCCEED;

}
