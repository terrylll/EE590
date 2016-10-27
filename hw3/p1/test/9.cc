#include "test.hh"
#include "fraction.hh"

int main () {

  // Part viii: Overload the << operator for ostreams and
  // show you can print fractions nicely.

  //Test 1: Print the fraction
  fraction a(3,4);
  fraction b(1,6);
  fraction c(2,5);

  cout <<"\n"<< a << endl;
  cout << b << endl;
  cout << c << endl;


  SUCCEED;
}
