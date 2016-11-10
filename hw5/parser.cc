#include "parser.hh"


Parser::Parser ( std::string str ) : tok(str) {
}

Object * Parser::array ( void ) {

  Array * a = new Array();

  tok.eat_punctuation('[');
  int i = 0;

  while ( !tok.current().matches(']') ) {
    a->set(i++,object());
    if ( tok.current().matches(',')) {
      tok.eat_punctuation(',');
      if ( tok.current().matches(']') ) {
        throw ParserException("Unexpected end of array");
      }
    }
  }

  tok.eat_punctuation(']');

  return a;

}

Object * Parser::hash ( void ) {

  Hash * h = new Hash();

  tok.eat_punctuation('{');

  while ( !tok.current().matches('}') ) {

    if ( tok.current().is_string() ) {

      std::string key = tok.current().string_val();
      tok.eat();
      tok.eat_punctuation(':');
      h->set(key,object());

      if ( tok.current().matches(',')) {
        tok.eat_punctuation(',');
        if ( tok.current().matches('}') ) {
          throw ParserException("Unexpected end of hash");
      }
    }
  }
    else {
 throw ParserException("Expected string");
    }
  }
  tok.eat_punctuation('}');
  return h;
}

Object * Parser::factor ( void ) {
  if ( tok.current().is_number() ) {
    double num = tok.current().number_val();
    tok.eat();
    Number * n = new Number(num);
    return n;
 }
  // else if (tok.current().matches('(')){
  //   tok.eat_punctuation('(');
  //   Number * o = expression();
  //   double num = o->get_val();
  //   delete o;
  //   tok.eat_punctuation(')');
  //   Number * n = new Number(tok.current().number_val());
  //   return n;
  // }
 else {
    throw ParserException("bad");
  }
}

Object * Parser::term (void) {
  factor();

}

Object * Parser::expression(void) {
  if ( tok.current().matches('+')){
    tok.eat_punctuation('+');


  } else if (tok.current().matches('-') ){
    tok.eat_punctuation('-');
  }
  term();

}

Object * Parser::null ( void ) {
  tok.eat();
  return new Null;
}

Object * Parser::boolean ( void ) {
  Boolean * b = new Boolean(tok.current().bool_val());
  tok.eat();
  return b;
}

Object * Parser::string ( void ) {
  String * s = new String(tok.current().string_val());
  tok.eat();
  return s;
}



Object * Parser::object ( void ) {

  if ( tok.current().matches('{') ) {
    return hash();
  } else if ( tok.current().matches('[') ) {
    return array();
  } else if ( tok.current().is_number()  || tok.current().matches('-') ) {
    return expression();
  } else if ( tok.current().is_null() ) {
    return null();
  } else if ( tok.current().is_bool() ) {
    return boolean();
  } else if ( tok.current().is_string()) {
    return string();
  } else {
    std::string s("Unexpected token ");
    s += tok.current().to_s();
    throw ParserException(s.c_str());
  }

}
