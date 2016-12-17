extern crate nalgebra;
use std::str;
use std::ops::Add;
use std::ops::Sub;
use std::ops::Mul;


struct Complex{
   re:f64,
   im:f64,
}
struct Matrix2 {
  m11:f64, m21:f64,
  m12:f64, m22:f64
}
struct Matrix3 {
   m11: f64,  m21: f64,  m31: f64,
   m12: f64,  m22: f64,  m32: f64,
   m13: f64,  m23: f64,  m33: f64
}
struct Matrix2Complex {
  m11:Complex, m21:Complex,
  m12:Complex, m22:Complex,
}

impl Matrix2 {
  pub fn new(m11: f64, m12: f64, m21:f64, m22:f64) -> Matrix2 {
    Matrix2 {m11:m11, m12:m12, m21:m21, m22:m22}
}
pub fn determinant(&self) -> f64 {
  self.m11 * self.m22 - self.m12 * self.m21
    }
}

impl Matrix3 {
  pub fn new(m11: f64, m12: f64, m13: f64, m21: f64, m22: f64, m23: f64, m31: f64, m32: f64, m33: f64) -> Matrix3 {
    Matrix3 {m11:m11,m12:m12,m13:m13,m21:m21,m22:m22,m23:m23,m31:m31,m32:m32,m33:m33}
  }
  pub fn determinant(&self) -> f64 {
    let minor_m12_m23 = self.m22 * self.m33 - self.m32 * self.m23;
    let minor_m11_m23 = self.m21 * self.m33 - self.m31 * self.m23;
    let minor_m11_m22 = self.m21 * self.m32 - self.m31 * self.m22;
    self.m11 * minor_m12_m23 - self.m12 * minor_m11_m23 + self.m13 * minor_m11_m22
      }
}

impl Complex {
  pub fn new(re:f64, im:f64) -> Complex {
  Complex {re:re, im:im}
  }
}

impl Matrix2Complex {
  pub fn new(m11: Complex, m12: Complex, m21:Complex, m22:Complex) -> Matrix2Complex{
    Matrix2Complex {m11:m11, m12:m12, m21:m21, m22:m22}
  }
}

impl Add for Matrix2 {
  type Output = Matrix2;
  fn add(self, other: Matrix2) -> Matrix2 {
		Matrix2 {m11: self.m11 + other.m11, m12: self.m12 + other.m12,
             m21: self.m21 + other.m21, m22: self.m22 + other.m22}
  }
}
impl Add for Matrix3 {
  type Output = Matrix3;
  fn add(self, other: Matrix3) -> Matrix3 {
		Matrix3 {m11: self.m11 + other.m11, m12: self.m12 + other.m12, m13: self.m13 + other.m13,
             m21: self.m21 + other.m21, m22: self.m22 + other.m22, m23: self.m23 + other.m23,
             m31: self.m31 + other.m31, m32: self.m32 + other.m32, m33: self.m33 + other.m33}
  }
}
impl Sub for Matrix2 {
  type Output = Matrix2;
  fn sub(self, other: Matrix2) -> Matrix2 {
		Matrix2 {m11: self.m11 - other.m11, m12: self.m12 - other.m12,
             m21: self.m21 - other.m21, m22: self.m22 - other.m22}
  }
}
impl Sub for Matrix3 {
  type Output = Matrix3;
  fn sub(self, other: Matrix3) -> Matrix3 {
		Matrix3 {m11: self.m11 - other.m11, m12: self.m12 - other.m12, m13: self.m13 - other.m13,
            m21: self.m21 - other.m21, m22: self.m22 - other.m22, m23: self.m23 - other.m23,
            m31: self.m31 - other.m31, m32: self.m32 - other.m32, m33: self.m33 - other.m33}
  }
}
impl Mul for Matrix2 {
  type Output = Matrix2;
  fn mul(self, other: Matrix2) -> Matrix2 {
		Matrix2 {m11: self.m11 * other.m11 + self.m12 * other.m21,
             m12: self.m11 * other.m12 + self.m12 * other.m22,
             m21: self.m21 * other.m11 + self.m22 * other.m21,
             m22: self.m21 * other.m12 + self.m22 * other.m22}
    }
}
impl Mul for Matrix3 {
  type Output = Matrix3;
  fn mul(self, other: Matrix3) -> Matrix3 {
		Matrix3 {m11: self.m11 * other.m11 + self.m12 * other.m21 + self.m13 * other.m31,
            m12: self.m11 * other.m12 + self.m12 * other.m22 + self.m13 * other.m32,
            m13: self.m11 * other.m13 + self.m12 * other.m23 + self.m13 * other.m33,
            m21: self.m21 * other.m11 + self.m22 * other.m21 + self.m23 * other.m31,
            m22: self.m21 * other.m12 + self.m22 * other.m22 + self.m23 * other.m32,
            m23: self.m21 * other.m13 + self.m22 * other.m23 + self.m23 * other.m33,
            m31: self.m31 * other.m11 + self.m32 * other.m21 + self.m33 * other.m31,
            m32: self.m31 * other.m12 + self.m32 * other.m22 + self.m33 * other.m32,
            m33: self.m31 * other.m13 + self.m32 * other.m23 + self.m33 * other.m33}
  }
}
impl Mul<f64> for Matrix2 {
    type Output = Matrix2;
    fn mul(self, other: f64) -> Matrix2 {
      Matrix2 {m11: self.m11 * other,
              m12: self.m12 * other,
              m21: self.m21 * other,
              m22: self.m22 * other }
          }
}
impl Mul<f64> for Matrix3 {
    type Output = Matrix3;
    fn mul(self, other: f64) -> Matrix3 {
      Matrix3 {m11: self.m11 * other,
              m12: self.m12 * other,
              m13: self.m13 * other,
              m21: self.m21 * other,
              m22: self.m22 * other,
              m23: self.m23 * other,
              m31: self.m31 * other,
              m32: self.m32 * other,
              m33: self.m33 * other}
  }
}
impl ToString for Complex {
	fn to_string(&self) -> String {
    if self.im > 0.0 {
	   format!("{}+{}i",self.re,self.im)
   }
    else if self.re == 0.0 {
      format!("{}i",self.im)
    }
    else if self.im == 0.0 {
      format!("{}",self.re)
    }
    else {
      format!("{}{}i",self.re,self.im)
    }
	}
}

impl ToString for Matrix2 {
	fn to_string(&self) -> String {
    format!("{} {} \n{} {}\n",self.m11,self.m12,self.m21,self.m22)
	}
}
impl ToString for Matrix2Complex {
	fn to_string(&self) -> String {
    format!("{}+{}i {}+{}i\n{}+{}i {}+{}i\n",self.m11.re,self.m11.im,self.m12.re,self.m12.im,self.m21.re,self.m21.im,self.m22.re,self.m22.im)
	}
}

impl ToString for Matrix3 {
	fn to_string(&self) -> String {
    format!("{} {} {}\n{} {} {}\n{} {} {}",self.m11,self.m12,self.m13,self.m21,self.m22,self.m23,self.m31,self.m32,self.m33)
	}
}

fn main() {
  //3x3 Matrix
    let a = Matrix3::new(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0).to_string();
    print!("1:\n{}\n",a);
    let b = (Matrix3::new(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0)+Matrix3::new(2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0)).to_string();
    print!("2:\n{}\n",b);
    let c = (Matrix3::new(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0)-Matrix3::new(2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0)).to_string();
    print!("3:\n{}\n",c);
    let d = (Matrix3::new(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0)*Matrix3::new(2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0)).to_string();
    print!("4:\n{}\n",d);
    let e = (Matrix3::new(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0)*2.0).to_string();
    print!("5:\n{}\n",e);
    let f = Matrix3::new(2.0,5.0,6.0,4.0,5.0,6.0,7.0,3.0,9.0).determinant();
    print!("6:\n{}\n",f);
    //2x2 Matrix
    let g = Matrix2::new(2.0,4.0,5.0,7.0).to_string();
    print!("7:\n{}\n",g);
    let h = (Matrix2::new(2.0,4.0,5.0,7.0)+Matrix2::new(2.0,4.0,5.0,7.0)).to_string();
    print!("8:\n{}\n",h);
    let i = (Matrix2::new(2.0,4.0,5.0,7.0)*Matrix2::new(2.0,4.0,5.0,7.0)).to_string();
    print!("9:\n{}\n",i);
    let j = Matrix2::new(2.0,4.0,5.0,7.0).determinant();
    print!("10:\n{}\n",j);
    //2x2 Matrix with complex number
    let k = Matrix2Complex::new(Complex::new(1.0,2.0),Complex::new(1.0,2.0),Complex::new(1.0,2.0),Complex::new(1.0,2.0)).to_string();
     print!("11:\n{}\n",k);
    let l = Complex::new(1.0,2.0).to_string();
    print!("12:\n{}\n",l);

}
