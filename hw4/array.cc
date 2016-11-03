#include "array.hh"
#include "null.hh"
#include "exception.hh"

Array::Array() {
  max = 10;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = NULL;
    length = max;
  }
}

Array::Array ( const Array &array ) {

  max = array.max;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {

    values[i] = array.values[i];
  }

}
// Destructor for Array class
Array::~Array() {
  delete []values;
}

int Array::getlength(){
  return length;
}

void Array::set(int index, Object &object) {
    if ( values[index] != NULL ) {
    delete values[index];
  }
  values[index] = object.clone();
}

Object* Array::get(int index) {
  if ( 0 <= index && index < max && values[index] != NULL ) {
    return values[index];
  } else {
    throw exception("Array out of Bound");
  }
}

std::string Array::stringify() {

  std::string s = "[";

  int m = -1;

  for ( int i=0; i<max; i++ ) {
    if ( values[i] != NULL ) {
      m = i;
    }
  }

  for ( int i=0; i<=m; i++ ) {
    if ( values[i] != NULL ) {
      s += values[i]->stringify();
    } else {
      s += "null";
    }
    if ( i < m ) {
      s += ",";
    }
  }

  s += "]";

  return s;

}
