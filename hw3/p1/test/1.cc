#include "test.hh"
#include "fraction.hh"

int main ( ) {

  // CONSTRUCTOR TESTS
  // Part i.
  // TEST 1: Write the fraction
  fraction a(3,4); //example

  cout <<"\n"<< a << endl;
  ASSERT (a.numerator == 3 && a.denominator == 4);
  SUCCEED;

}
