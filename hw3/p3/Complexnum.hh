// #ifndef Complexnum
// #define Complexnum
// #endif
#define _USE_MATH_DEFINES
#ifndef pi
#define pi         (3.14159265358979323) /* pi */
#endif

#include <iostream>
#include <cmath>
using namespace std;

class Complexnum {
    private:

    public:
        double r, i;
        double real, imagine;
        // const double pi = atan(1.0)*4;

      Complexnum(double real =0.0, double imagine=0.0);
      // ~Complexnum();

       Complexnum(Complexnum&);

        Complexnum (const Complexnum &Complexnum):
          r(Complexnum.r), i(Complexnum.i)
          {  }

        operator int() {return r;}
        Complexnum(int n):Complexnum(n,0) {};
        inline Complexnum operator = (int n) {
          return Complexnum(n);
        }

        Complexnum operator - ()const {
          Complexnum t(r*-1,i*-1);
          return t;
          }

        double pow(double b, double p);
        friend Complexnum powerofe(const Complexnum &a);
        friend Complexnum conjugate(const Complexnum &a);
        friend Complexnum magnitude(const Complexnum &a);
        friend Complexnum angle(const Complexnum &a);
        friend Complexnum operator ^ (const Complexnum &a, double b);

        friend ostream& operator << (ostream& out, const Complexnum &a);
        friend Complexnum operator + (const Complexnum &a,const Complexnum &b);
        friend Complexnum operator - (const Complexnum &a,const Complexnum &b);
        friend Complexnum operator * (double b, const Complexnum &a);
        friend Complexnum operator * (const Complexnum &a, double b);
        friend Complexnum operator * (const Complexnum &a,const Complexnum &b);
        friend Complexnum operator / (const Complexnum &a,const Complexnum &b);
};

#include "ComplexOP.cc"
