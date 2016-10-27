#include "test.hh"
#include "fraction.hh"

int main ( ) {

  // part ii
  // Test 1: A copy constructor.
  fraction a(3,4); // example

  fraction fcopy(a);
  std::cout<<"\n"<< fcopy << endl;
  ASSERT (fcopy.numerator == 3 && fcopy.denominator == 4);
  SUCCEED;
}
