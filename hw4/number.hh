#include "object.hh"

class Number : public Object {

public:

  Number(double d);
  // Destructor for Number class
  ~Number(){

  }
  Number ( const Number &number ) { value = number.value; }

  Number * clone() { return new Number(*this); }
  inline void set(double d) { value = d; }
  std::string stringify();

private:

  double value;

};
