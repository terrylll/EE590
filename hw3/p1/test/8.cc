#include "test.hh"
#include "fraction.hh"

int main () {

  // Part viii: Raising a fraction to a power.


  fraction a(3,4);
  fraction b;
  // Test 1: Power of 2
  b = a ^ 2;
  cout <<"\n"<< b << "\tshould be equal to 9/16" << endl;
  ASSERT (b.numerator == 9 && b.denominator == 16);

  // Test 2: Power of 3
  b = a ^ 3;
  cout << b << "\tshould be equal to 27/64" << endl;
  ASSERT (b.numerator == 27 && b.denominator == 64);

  SUCCEED;
}
