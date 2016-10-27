#include "test.hh"
#include "fraction.hh"

int main () {

  // Part vii: All relations: ==, !=, <, >, <=, >=.

  //Test 1: Test for ==
  fraction a(3,4); // example a
  fraction b(1,6);// example b

  if(a == b){
    cout << "Fraction a is equal to Fraction b" << endl;
  }else {
    cout << "Fraction a is not equal to Fraction b" << endl;
  }
  //Test 2: Test for !=
  if(a != b){
    cout << "Fraction a is not equal to Fraction b" << endl;
  }else {
    cout << "Fraction a is equal to Fraction b" << endl;
  }
 //Test 3: Test for >
  if(a > b){
    cout << "Fraction a is larger than Fraction b" << endl;
  }else {
    cout << "Fraction a is smaller than Fraction b" << endl;
  }
  //Test 4: Test for <
  if(a < b){
    cout << "Fraction a is smaller than Fraction b" << endl;
  }else {
    cout << "Fraction a is larger than Fraction b" << endl;
  }
  //Test 5: Test for <=
  if(a <= b){
    cout << "Fraction a is smaller or equal than Fraction b" << endl;
  }else {
    cout << "Fraction a is larger than Fraction b" << endl;
  }
  //Test 6: Test for >=
  if(a >= b){
    cout << "Fraction a is larger or equal than Fraction b" << endl;
  }else {
    cout << "Fraction a is smaller than Fraction b" << endl;
  }


  SUCCEED;
}
