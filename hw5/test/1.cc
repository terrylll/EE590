#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  //Tokenizer tok("{ \"first\": [ true, \"a\", \"b\", \"c\" ], \"second\": 1.234 }");

  Tokenizer tok("{ [1+1,2.2,3e20,5.5,7.8,6e6,2.5e6,3.5e8,-2,-3.5,6e-12,1.2e-6] }");

  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  return 0;

}
