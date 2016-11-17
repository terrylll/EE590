Tokenizer = require('./tokenizer.js');

t = new Tokenizer();

t.add(/\[/)
 .add(/\d+/)
 .add(/,/)
 .add(/]/)
 // .add(/\d\.?\d+/)
 .tokenize("[ 1.1, 200,300, ,,[][]]");

console.log(t.tokens);
