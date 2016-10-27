#include "test.hh"
#include "matrix.hh"
// Unit Test part 1: Test for ADD method
int main ( int argc, char * argv[] ) {

  matrix<double> A(3,3);

  try {
     matrix<double> D(4,3), E(3,5);
     A = D.add(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

}
