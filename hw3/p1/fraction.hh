#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

class fraction {
    private:

        int gcd(int a, int b) {
            while (a != b) {
                if (a > b) {
                    a -= b;
                } else {
                    b -= a;
                }
            }
            return a;
        }

    public:
        int numerator, denominator, tem,x,y,z;

        fraction() {
            numerator = 0;
            denominator = 1;
        }

        fraction(int n, int d) {
            if (d==0) {
              cout << "Denominator can not be 0." << endl;
              exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                int sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                int temp = gcd(n, d);
                numerator = n/temp*sign;
                denominator = d/temp;
            }
        }

        operator int() {return (numerator)/denominator;}

        fraction (const fraction &fraction):
          numerator(fraction.numerator), denominator(fraction.denominator)
          {  }

        friend std::ostream& operator << (std::ostream& out, const fraction &f1);

        fraction(int n):fraction(n,1) {};
        inline fraction operator = (int n) { return fraction(n); }

        fraction operator - ()const {
         fraction t(-numerator,denominator);
         return t;
        }
        bool operator == (double a) const ;
         bool operator == (const fraction& a) const;
         bool operator != (const fraction& a) const;
         bool operator > (const fraction& a) const;
         bool operator < (const fraction& a) const;
         bool operator >= (const fraction& a) const;
         bool operator <= (const fraction& a) const;
      //   operator ^ (int b);


};
bool fraction::operator == (double a) const {
  return (numerator==a) && (denominator==1);
}

bool fraction::operator == (const fraction& a) const {
  return (numerator==a.numerator) && (denominator==a.denominator);
}

bool fraction::operator != (const fraction& a) const {
  return (numerator!=a.numerator) && (denominator!=a.denominator);
}

bool fraction::operator > (const fraction& a) const {
   if( float (numerator/denominator) > float (a.numerator/a.denominator)){
     return true;
   } else if ( float (numerator/denominator) < float (a.numerator/a.denominator)) {
     return false;
   }
    else {
    return false;
    }
}

bool fraction::operator < (const fraction& a) const {
  if( float (numerator/denominator) < float (a.numerator/a.denominator)){
    return true;
  } else if ( float (numerator/denominator) > float (a.numerator/a.denominator)) {
    return false;
  }
   else {
   return false;
   }
}

bool fraction::operator >= (const fraction& a) const {
  if( float (numerator/denominator) >= float (a.numerator/a.denominator)){
    return true;
  } else if ( float (numerator/denominator) < float (a.numerator/a.denominator)) {
    return false;
  }
   else {
   return false;
   }
}

bool fraction::operator <= (const fraction& a) const {
  if( float (numerator/denominator) <= float (a.numerator/a.denominator)){
    return true;
  } else if ( float (numerator/denominator) > float (a.numerator/a.denominator)) {
    return false;
  }
   else {
   return false;
   }
}

fraction operator ^ (const fraction& a, int b) {
  int x = a.numerator;
  int y = a.denominator;
  int tem1,tem2;
  for (int i=0; i<b-1; i++){
      tem1 = a.numerator;
      x *= tem1;
    }
    for (int i =0; i<b-1; i++){
      tem2 = a.denominator;
      y *= tem2;
    }
  fraction temp(x,y);
  return temp;
}

fraction operator + (const fraction& a, const fraction& b) {
    fraction temp(a.numerator*b.denominator
                +b.numerator*a.denominator,
                a.denominator*b.denominator);
    return temp;
}

fraction operator - (const fraction& a, const fraction& b) {
  // if (a.numerator == EOF){
  //   return fraction(-1*b.numerator,b.denominator);
  // }else {
    fraction temp(a.numerator*b.denominator
                -b.numerator*a.denominator,
                a.denominator*b.denominator);
    return temp;
        // }
}

fraction operator * (const fraction& a, const fraction& b) {

    fraction temp(a.numerator*b.numerator,
               a.denominator*b.denominator);
    return temp;
}

fraction operator * (double a, const fraction& b) {
    fraction temp(a*b.numerator,b.denominator);
    return temp;
}

fraction operator * (const fraction& b, double a) {
    fraction temp(a*b.numerator,b.denominator);
    return temp;
}

fraction operator / (const fraction& a, const fraction& b) {
    fraction temp(a.numerator*b.denominator,
                 a.denominator*b.numerator);
    return temp;
}

fraction operator / (const fraction& a, double b) {
    fraction temp(a.numerator/b,
                 a.denominator/b);
    return temp;
}


std::ostream& operator << (std::ostream &strm, const fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}
