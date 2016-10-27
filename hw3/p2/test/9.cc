#include "test.hh"
#include "Complexnum.hh"

// Part ix: Raising e to the power of a given complex number 
int main ( ) {

  Complexnum a(0,pi);
  Complexnum b(6,-5);
  Complexnum c;

  // Test 1:
  c = powerofe(a);

  cout <<"\n"<< c << endl;
  SUCCEED;

}
