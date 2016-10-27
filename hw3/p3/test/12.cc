#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part ii:  ALL methods for matrix of type int
int main ( int argc, char * argv[] ) {
  // Test 2: Scale function
  // S = S * d
    matrix<int> S(2,2);

    S.set(0,0,1); S.set(0,1,2);
    S.set(1,0,3); S.set(1,1,4);
    double d = 2;
    S.scale(d);
    ASSERT(S.get(0,0) == 2 && S.get(0,1) == 4 && S.get(1,0) == 6 && S.get(1,1) == 8);

}
