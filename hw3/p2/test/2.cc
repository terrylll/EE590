#include "test.hh"
#include "Complexnum.hh"

// Part ii: A copy constructor
int main ( ) {

// Test 1:
  Complexnum a(3,4); //example
  Complexnum fcopy = a;
  cout <<"\n"<< fcopy << endl;

  ASSERT(fcopy.r == 3 &&fcopy.i == 4);
  SUCCEED;

}
