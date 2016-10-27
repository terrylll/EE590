
 Complexnum::Complexnum(double rr, double ii):r(rr), i(ii){
 }

ostream& operator << (ostream &strm, const Complexnum &a) {
      if (a.i >= 0 && a.i <= 0.00001) {
        strm << a.r << endl;
      } else if (a.i < 0) {
        strm << a.r <<  a.i <<"i"<<endl;
      } else {
        strm << a.r << "+" << a.i << "i";
      }
    return strm;
}

Complexnum::Complexnum(Complexnum &a) {
  this->r = a.r;
  this->i = a.i;
}


Complexnum conjugate(const Complexnum &a) {
  Complexnum temp(a.r,a.i*-1);

  return temp;
}

Complexnum magnitude(const Complexnum &a) {
  double temp;
  temp = sqrt((a.r)*(a.r) + (a.i)*(a.i));
  return temp;
}

Complexnum angle(const Complexnum &a) {
  double temp;
  temp = atan(a.i / a.r);
  return temp;
}

Complexnum powerofe(const Complexnum &a) {
    Complexnum temp(cos(a.i),sin(a.i));

    return temp;
}

Complexnum operator ^ (const Complexnum &a, double b) {

  Complexnum temp(pow((a.r*a.r+a.i*a.i),(b/2))*cos(b*atan(a.i/a.r)),
                pow((a.r*a.r+a.i*a.i),(b/2))*sin(b*atan(a.i/a.r)) );

  return temp;
}
Complexnum  operator + (const Complexnum &a, const Complexnum &b){
  Complexnum temp(a.r + b.r,a.i + b.i);

  return temp;
}

Complexnum operator - (const Complexnum &a, const Complexnum &b){
  Complexnum temp(a.r - b.r,a.i - b.i);

  return temp;

}

Complexnum operator * (double b, const Complexnum &a){
  Complexnum temp(a.r * b, a.i * b);

  return temp;

}

Complexnum operator * (const Complexnum &a, double b){
  Complexnum temp(a.r * b, a.i * b);

  return temp;

}

Complexnum operator * (const Complexnum &a, const Complexnum &b){
  Complexnum temp(a.r * b.r - a.i * b.i,a.r * b.i + a.i * b.r);

  return temp;

}

Complexnum operator / (const Complexnum &a, const Complexnum &b){
  Complexnum temp((a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i),
              (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i) );

  return temp;

}
