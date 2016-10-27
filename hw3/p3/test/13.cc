#include <iostream>
#include "test.hh"
#include "matrix.hh"
// Part ii:  ALL methods for matrix of type int
int main ( int argc, char * argv[] ) {
// Test 3: Minor function

    matrix<int> S(2,2);

    S.set(0,0,1); S.set(0,1,2);
    S.set(1,0,3); S.set(1,1,4);

   matrix<int> M = S.minor(0,0);

      ASSERT(M.get(0,0) == 4);


}
