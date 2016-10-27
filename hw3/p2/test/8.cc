#include "test.hh"
#include "Complexnum.hh"

// Test viii: Raising a complex number to a power.
int main ( ) {

  Complexnum a(3,4);
  Complexnum b(6,-5);
  Complexnum c;

  // Test 1:
  c = a^ 1.5;

  cout <<"\n"<< c << endl;

  SUCCEED;

}
