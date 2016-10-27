#include "test.hh"
#include "Complexnum.hh"

// Part vii: Magnitude and angle methods. Angle should be in radians.
int main ( ) {

  Complexnum a(3,4);
  Complexnum b(6,-5);
  Complexnum c;

  // Test 1: Test for magnitude
  c = magnitude(a);
  cout <<"\n"<< c << endl;
  ASSERT(c == 5);

 // Test 2: Test for angle in radians
  c = angle(a);
  cout <<"\n"<< c << endl;

  SUCCEED;

}
