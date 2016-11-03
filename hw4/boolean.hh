#include "object.hh"
#include <string>
class Boolean : public Object {

public:

  Boolean(std::string d);
  // Destructor for Boolean class
  ~Boolean(){

  }
  Boolean ( const  Boolean &boolean ) { value = boolean.value; }

  virtual Boolean * clone() { return new Boolean(*this); }
  virtual inline void set(std::string d) { value = d; }
  virtual std::Boolean stringify();

private:

   std::Boolean value;

};
