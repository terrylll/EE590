Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed
  this.re;
  this.tokens = [];

  this.tokenizer = new Tokenizer();

  this.tokenizer
      .add(/\+/)
      .add(/-/) // Add tokens here
      .add(/\d+(?!\.)/ )
      .add(/\d\.?\d+/)
      .add(/\*/)
      .add(/\//)
      .add(/\./);

}

Parser.prototype.factor = function() {
  // TODO
  if (this.tokenizer.current() == '(') {
    this.tokenizer.eat();
     if (this.tokenizer.current() == '-'){
      this.unary();
     }
    this.exr();

  }
  else if  ( !(isNaN(this.tokenizer.current())) ){
    num = this.tokenizer.current();
    num = this.tokenizer.float_val();
    this.tokenizer.eat();
    return num;
  }

   else {
     return this.tokenizer.eat();
   }
}
Parser.prototype.term = function() {

  this.factor();

  while (this.tokenizer.current() == '*' || this.tokenizer.current() == '/') {

     if (this.tokenizer.current() == '*'){
       this.tokenizer.eat();
       num = num * this.exr();
     }
    else if (this.tokenizer.current() == '/'){
        this.tokenizer.eat();
       num = num / this.exr();
     }
    this.factor()
  }
  return num;
}

Parser.prototype.exr = function() {
  //  num = this.tokenizer.current();  //  num = this.tokenizer.float_val()  //  this.tokenizer.eat();
   if(this.tokenizer.current() == '+'|| this.tokenizer.current() == '-') {
     if (this.tokenizer.current() == '+') {
      this.tokenizer.eat();
      num = num + this.term();
      this.tokenizer.eat();
    }
     else if (this.tokenizer.current() == '-') {
         this.tokenizer.eat();
         num = num - this.term();
         this.tokenizer.eat();
   }
 }
   this.term();
   while (this.tokenizer.current() == '+'|| this.tokenizer.current() == '-'){

     if (this.tokenizer.current() == '+') {
       this.tokenizer.eat();
       num = num + this.term();
   }
     else if (this.tokenizer.current() == '-') {
       this.tokenizer.eat();
       num = num - this.term();
  }
  // this.tokenizer.eat();
  // this.factor();
   }
  return num;
}

Parser.prototype.unary = function() {
  this.tokenizer.eat();
  num = 0 - this.tokenizer.float_val();
  this.tokenizer.eat();
  return num;
}

Parser.prototype.parse = function() {
  this.tokenizer.tokenize(this.str)
  if ( this.tokenizer.current() == '(' ) {
  return this.exr();
} else if ( this.tokenizer.current() == '+' ) {
  return this.exr();
} else if ( this.tokenizer.current() == '-' ) {
  return this.exr();
} else {
  return this.exr();
  }
}

module.exports = Parser;
