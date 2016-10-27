#include "test.hh"
#include "fraction.hh"

int main () {

  // Part vi: Overload '-', the unary minus operator to negate a fraction

  //Test 1:
  fraction a(3,4); // example a
  fraction b(1,6);// example b
  fraction c;

  c = -a;
  cout <<"\n"<< c <<"\tShould be equal -3/4"<< endl;


  SUCCEED;
}
