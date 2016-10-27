#include "test.hh"
#include "Complexnum.hh"
// Part v: Addition, subtraction multiplication, and division.

int main ( ) {

  Complexnum a(3,4);
  Complexnum b(6,5);
  Complexnum c;

  // Test 1: Addition

  c = a + b;
  cout <<"\n"<< c << endl;
  ASSERT(c.r == 9 && c.i == 9);
  // Test 2: Subtraction

  c = a - b;
  cout << c << endl;
  ASSERT(c.r == -3 && c.i == -1);
  // Test 3: multiplication

  c = a * b;
  cout << c << endl;
  ASSERT(c.r == -2 && c.i == 39);
  // Test 4: division

  c = a / b;
  cout<< c << endl;

  SUCCEED;

}
