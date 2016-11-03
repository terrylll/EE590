#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Number number(1.0);
  Array array;
  String n("number");

  array.set(0,n);
  number.set(2.0);
  array.set(1,number);
  array.set(3,array);

  std::cout << number.stringify() << std::endl;
  std::cout << array.stringify() << std::endl;
  // try to get an array value out of bound. e.g: array.get(4)
  std::cout << array.get(4)->stringify() << std::endl;
// The result should display "Array out of Bound"
  return 0;

}
