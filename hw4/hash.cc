#include "hash.hh"
#include "null.hh"
#include "exception.hh"
#include "array.hh"
#include "string.hh"
Hash::Hash() {


  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

}

Hash::Hash ( const Hash &hash ) {
  Bucket * ptr = new Bucket;
  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }
  for ( int i=0; i<num_shelves; i++ ) {
      ptr = shelves[i];
      ptr->key;

  }


  // TODO: method keys() that returns an Array of keys
  //           for ( k in keys() ) {
  //             set(k,hash.get(k))
  //           }

}
// Destructor for Hash
Hash::~Hash() {
}

void Hash::keys(){
Array key;
String N("");
Bucket * ptr;

int index = 0;

for ( int i=0; i<num_shelves; i++ ) {
  ptr = shelves[i];
  while ( ptr != NULL ) {
    std::cout << ptr->key << std::endl;
    N.set(ptr->key);
    key.set(index,N);
    ptr = ptr->next;
    index ++;
  }
}
return key;
}

void Hash::set ( std::string key, Object &value ) {

//   if ( shelves[key] != NULL ) {
//     delete shelves[key];
// }
  // TODO: Homework: Use delete if key exists to avoid duplicate keys
  //       or reset the value in place (make sure to delete old value!)

  int i = hash(key);

  Bucket * ptr = new Bucket;

  ptr->key = key;
  ptr->value = value.clone();
  ptr->next = shelves[i];
  shelves[i] = ptr;

}

Object * Hash::get ( std::string key ) {

  int i = hash(key);
  Bucket * ptr = shelves[i];

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  if ( ptr ) {
    return ptr->value;
  } else {
    throw exception("Key does not exist");
  }

}

int Hash::hash ( std::string s ) {

  int n = 0;

  for ( int i=0; i<s.length(); i++ ) {
    n += (int) s[i];
  }

  return n % num_shelves;

}

std::string Hash::stringify() {

  std::string s = "{";

  for ( int i=0; i<num_shelves; i++ ) {
    Bucket * ptr = shelves[i];
    while ( ptr != NULL ) {
      s += ptr->key + ":" + ptr->value->stringify() + ",";
      ptr = ptr->next;
    }
  }

  if ( s[s.length()-1] == ',' ) {
    s[s.length()-1] = '}';
  } else {
    s += "}";
  }

  return s;

}
