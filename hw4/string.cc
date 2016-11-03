#include "string.hh"

String::String(std::string d) : value(d) {
}



std::string String::stringify() {
  return std::string("\""+ value + "\"" );
}
