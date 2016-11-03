#include "object.hh"
#include <string>
class String : public Object {

public:

  String(std::string d);
  // Destructor for String class
  ~String(){

  }
  String ( const  String &string ) { value = string.value; }

  virtual String * clone() { return new String(*this); }
  virtual inline void set(std::string d) { value = d; }
  virtual std::string stringify();

private:

   std::string value;

};
