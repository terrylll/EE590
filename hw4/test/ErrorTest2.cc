#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Hash h;
  Number n(1);

  h.set("first", n);
  //h.set("second", h);
  // try to get a key which does not exist in the hush
  
  std::cout << h.stringify() << std::endl;
  std::cout << h.get("first")->stringify() << std::endl;
  std::cout << h.get("second")->stringify() << std::endl;
  // The result should display"Key does not exist"


  // next line will fail until the copy constructor for Hash is implemented
  std::cout << h.get("second")->get("first")->stringify() << std::endl;

  return 0;

}
