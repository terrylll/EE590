#include "test.hh"
#include "Complexnum.hh"

// Part i: A constructor so you can write, for example, complex x(3,4),
// to get 3 + 4i.
int main ( ) {

  // Test 1:
  Complexnum a(3,4); //example

  cout <<"\n"<< a << endl;
  ASSERT(a.r == 3 && a.i ==4);
  
  SUCCEED;

}
