extern crate num;
use std::str;
use std::ops::Add;
use std::ops::Sub;
use std::ops::Mul;
use std::ops::Div;

struct Complex{
  pub re:f32,
  pub im:f32,
}

impl Complex {
  //Create new complex number
  pub fn new(re:f32, im:f32) -> Complex {
    Complex {re:re, im:im}
  }
  //Conjunction
  pub fn conj(&self) -> Complex {
    Complex {re:self.re , im:-self.im}
  }
  //Magnitude of complex number
  pub fn norm(&self) -> Complex {
    Complex {re:(self.re*self.re + self.im * self.im).sqrt(), im: 0.0}
  }
  //Angle of complex number
  pub fn arg(&self) -> Complex {
    Complex {re: self.im.atan2(self.re), im: 0.0}
  }
  //
  pub fn from_polar(r: f32, theta: f32) -> Complex {
    Complex::new(r * theta.cos(), r * theta.sin())
  }
  //
  pub fn to_polar(&self) -> (f32,f32) {
    ((self.re*self.re + self.im * self.im).sqrt(),self.im.atan2(self.re))
  }
  //complex number power to float value
  pub fn powf(&self, exp:f32) -> Complex {
    let (r, theta) = self.to_polar();
    Complex::from_polar(r.powf(exp), (theta*exp))
  }
  //e power to complex number
  pub fn exp(&self) -> Complex {
    Complex::from_polar(self.re.exp(), self.im)
  }
}
// Tostring to display the value
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

// Overload Add Operation (+)
impl Add for Complex {
  type Output = Complex;
  fn add(self, other: Complex) -> Complex{
		Complex{re: self.re + other.re , im: self.im + other.im}
  }
}
// Overload Substract Operation (-)
impl Sub for Complex {
  type Output = Complex;
  fn sub(self, other: Complex) -> Complex{
		Complex{re: self.re - other.re , im: self.im - other.im}
  }
}
// Overload Mulplite Operation (*)
impl Mul for Complex {
    type Output = Complex;
    fn mul(self, other: Complex) -> Complex {
        Complex{re: self.re * other.re - self.im * other.im,
                im: self.re * other.im + self.im * other.re}
  }
}
impl Mul<f32> for Complex {
    type Output = Complex;
    fn mul(self, other: f32) -> Complex {
        Complex{re: self.re * other,
                im: self.re * other}
  }
}
// Overload Substract Operation (/)
impl Div for Complex {
  type Output = Complex;
  fn div(self, other: Complex) -> Complex{
		Complex{re: (self.re * other.re + self.im * other.im)/(other.re *other.re + other.im*other.im),
            im: (self.im * other.re - self.re * other.im)/(other.re *other.re + other.im*other.im)}
  }
}
//Testing
//Run "cargo test" in the command pannel
#[test]
fn create() {
  assert!(Complex::new(2.0,-2.0).to_string()=="2-2i");
}

#[test]
fn add_function(){
  assert!((Complex::new(2.0,-2.0)+Complex::new(2.0,-2.0)).to_string() == "4-4i");
}

#[test]
fn sub_function(){
  assert!((Complex::new(3.0,-3.0)-Complex::new(2.0,-2.0)).to_string() == "1-1i");
}

#[test]
fn mul_function(){
  assert!((Complex::new(3.0,-3.0)*Complex::new(2.0,-2.0)).to_string() == "-12i");
}

#[test]
fn mul_function2(){
  assert!((Complex::new(3.0,-3.0)*2.0).to_string() == "6+6i");
}

#[test]
fn conjunction(){
  assert!(Complex::new(2.0,-2.0).conj().to_string()=="2+2i");
}

#[test]
fn magitude(){
  assert!(Complex::new(4.0,3.0).norm().to_string()=="5");
}

fn main() {
    let a = Complex::new(2.0,-2.0).to_string();
    println!("1:{:?}",a);
    let b = (Complex::new(2.0,-2.0)+Complex::new(2.0,-2.0)).to_string();
    println!("2:{:?}",b);
    let c = (Complex::new(3.0,-3.0)-Complex::new(2.0,-2.0)).to_string();
    println!("3:{:?}",c);
    let d = (Complex::new(3.0,-3.0)*Complex::new(2.0,-2.0)).to_string();
    println!("4:{:?}",d);
    let e = (Complex::new(3.0,-3.0)*2.0).to_string();
    println!("5:{:?}",e);
    let f = (Complex::new(6.0,-3.0)/Complex::new(4.0,5.0)).to_string();
    println!("6:{:?}",f);
    let g = Complex::new(2.0,-2.0).conj().to_string();
    println!("7:{:?}",g);
    let h = Complex::new(4.0,3.0).norm().to_string();
    println!("8:{:?}",h);
    let i = Complex::new(3.0,-3.0).arg().to_string();
    println!("9:{:?}",i);
    let j = Complex::new(3.0,4.0).powf(3.0).to_string();
    println!("10:{:?}",j);
    let k = Complex::new(3.0,-3.0).exp().to_string();
    println!("11:{:?}",k);
}
