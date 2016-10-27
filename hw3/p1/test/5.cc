#include "test.hh"
#include "fraction.hh"

int main ( ) {

  // Part v: Addition, subtraction, multiplication, and division,
  // with overloaded operators. All operations should return the result
  // in lowest terms, and should leave their operands untouched
  // (using const and call by reference).

  //Test 1: Addition
  fraction a(3,4); // example a1
  fraction b(1,6);// example b1
  fraction c;

  c = a + b;
  cout <<"\n"<< c <<"\tShould be equal 11/12"<< endl;
  ASSERT (c.numerator ==11 &&c.denominator == 12);

  // Test 2: Subtraction
  
  c = a - b;
  cout << c <<"\tShould be equal 7/12"<< endl;
  ASSERT (c.numerator == 7 && c.denominator == 12);

  // Test 3: multiplication
  c = a * b;
  cout << c <<"\tShould be equal 1/8"<< endl;
  ASSERT (c.numerator == 1 && c.denominator == 8);

  // Test 4: Devision
  c = a / b;
  cout << c <<"\tShould be equal 9/2"<< endl;
  ASSERT (c.numerator == 9 && c.denominator == 2);

  SUCCEED;
}
