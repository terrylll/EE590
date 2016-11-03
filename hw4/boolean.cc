#include "boolean.hh"

Boolean::Boolean(std::string d) : value(d) {
}

std::string Boolean::stringify() {
  
  return std::string( "True" );
}
