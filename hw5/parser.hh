#ifndef _PARSER_H_
#define _PARSER_H_

#include "json.hh"
#include <cmath>

class ParserException : public std::runtime_error {
public:
  ParserException(const char msg[]) : std::runtime_error(msg) {}
};

class Parser {

public:

  Parser ( std::string str );

  Object * object ( void );
  Object * array ( void );
  Object * number ( void );
  Object * hash ( void );
  Object * null ( void );
  Object * boolean ( void );
  Object * string ( void );
  Object * expression(void);
  Object * factor ( void );
  Object * term ( void );
private:

  Tokenizer tok;

};

#endif
