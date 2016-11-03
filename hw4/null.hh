#include "object.hh"

class Null : public Object {

public:

  Null() {}
  // Destructor for Null class
  ~Null(){
  }

  Null * clone() { return new Null(*this); }
  std::string stringify() { return std::string("null"); }

};
