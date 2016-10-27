#include "test.hh"
#include "Complexnum.hh"

// Part x: Overload the << operator so you can print complex numbers nicely.
int main ( ) {

  Complexnum a(1,7);
  Complexnum b(6,-5);
  Complexnum c(-4,8);

  // Test 1:
  c = a;
  cout <<"\n"<< c << endl;


  SUCCEED;

}
