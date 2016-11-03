#include "object.hh"

class Array : public Object {

public:

  Array();
  //Destructor for Array class
  ~Array();
  Array ( const Array &array );
  Array * clone() { return new Array(*this); }

  void set(int index, Object &object);
  Object * get(int index);
  std::string stringify();
  int getlength();

private:

  int length;
  int max;
  Object ** values;

};
