#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>

class Object {

public:

  Object();
  // Destructor for Object class
  ~Object(){
  
  }
  Object ( const Object &m ) {}

  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;

  virtual Object * get() { throw "Undefined getter: get()"; }
  virtual Object * get(std::string s) { throw "Undefined getter: get(s)"; }
  virtual Object * get(int i) { throw "Undefined getter: get(i)"; }

};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }

#endif
