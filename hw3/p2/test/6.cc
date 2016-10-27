#include "test.hh"
#include "Complexnum.hh"

// Part vi: Unary negation
int main ( ) {

  Complexnum a(3,4);
  Complexnum b(6,-5);
  Complexnum c;

  // Test 1:
  c =-a;
  cout <<"\n"<< c << endl;
  ASSERT(c.r == -3 && c.i == -4);
// Test 2
  c =-b;
  cout <<"\n"<< c << endl;
  ASSERT(c.r == -6 && c.i == 5);

  SUCCEED;

}
