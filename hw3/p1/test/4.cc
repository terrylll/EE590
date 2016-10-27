#include "test.hh"
#include "fraction.hh"

int main () {

  // Part iv: Reduce a fraction to lowest terms (should return a new fraction).

  //Test 1
  fraction a(6,4);
  std::cout <<"\n"<< a <<"\tShould be equal 3/2"<< endl;

  //Test 2
  fraction b(16,6);
  std::cout << b <<"\tShould be equal 8/3"<< endl;

  //Test 3
  fraction c(6,18);
  std::cout << c <<"\tShould be equal 1/3"<< endl;

  SUCCEED;
}
