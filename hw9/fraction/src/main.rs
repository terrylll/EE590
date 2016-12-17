use std::str;
use std::ops::Add;
use std::ops::Sub;
use std::ops::Mul;
use std::ops::Div;
// Create a Struct function for Fraction
struct Fraction{
  x:i32,
  y:i32,
}
// Implement GCD function
impl Fraction {
  fn gcd(&mut self) -> Fraction {
    let mut x = self.x;
    let mut y = self.y;

    while x % y != 0 {
      let z = x % y;
      x=y;
      y=z;
    }

    let mut frac = Fraction{x:self.x/y,y:self.y/y};
    if frac.y<0 {
      frac.y=-frac.y;
      frac.x=-frac.x;
    }
    frac
  }

  pub fn new(x:i32,y:i32)->Fraction{
		if y<0 {
			Fraction{x:-x,y:-y}.gcd()
		}else{
			Fraction{x:x,y:y}.gcd()
		}
	}
  pub fn powf(&self,exp:u32) ->Fraction {
    Fraction {x: self.x.pow(exp), y: self.y.pow(exp) }
  }
}
// Create a string to fraction form. E.g. 3/7,5/9,1/2,etc
impl ToString for Fraction {
	fn to_string(&self) -> String {
		if self.y ==1 {
			format!("{}",self.x)
		} else {
      format!("{}/{}",self.x,self.y)
		}
	}
}
// Overload Add Operation (+)
impl Add for Fraction {
  type Output = Fraction;
  fn add(self, rhs:Fraction) -> Fraction{
		Fraction{x: self.x*rhs.y + rhs.x*self.y , y: self.y*rhs.y}.gcd()
  }
}
// Overload Substract Operation (-)
impl Sub for Fraction {
  type Output = Fraction;
  fn sub(self, rhs:Fraction) -> Fraction{
		Fraction{x: self.x*rhs.y - rhs.x*self.y , y: self.y*rhs.y}.gcd()
  }
}
// Overload Mulplite Operation (*)
impl Mul for Fraction {
  type Output = Fraction;
  fn mul(self, rhs:Fraction) -> Fraction{
		Fraction{x: self.x*rhs.x , y: self.y*rhs.y}.gcd()
  }
}
// Overload Divie Operation (/)
impl Div for Fraction {
  type Output = Fraction;
  fn div(self, rhs:Fraction) -> Fraction{
		Fraction{x: self.x*rhs.y , y: self.y*rhs.x}.gcd()
  }
}
//Testing fraction examples:
//Run "cargo test" in the command pannel
#[test]
fn create() {
  assert!(Fraction::new(3,8).to_string()=="3/8");
}

#[test]
fn create2() {
  assert!(Fraction::new(2,4).to_string()=="1/2");
}

#[test]
fn add_fraction() {
	assert!((Fraction::new(2,4)+Fraction::new(3,8)).to_string()=="7/8");
}

#[test]
fn sub_fraction() {
	assert!((Fraction::new(2,4)-Fraction::new(7,3)).to_string()=="-11/6");
}

#[test]
fn mul_fraction() {
	assert!((Fraction::new(2,4)*Fraction::new(7,3)).to_string()=="7/6");
}

#[test]
fn div_fraction() {
	assert!((Fraction::new(2,4)/Fraction::new(7,3)).to_string()=="3/14");
}

#[test]
fn power_fraction() {
	assert!((Fraction::new(3,4).powf(3)).to_string()=="27/64");
}
// Run "cargo run" in the command pannel to display all the examples
fn main() {
  let a = Fraction::new(3,8).to_string();
  println!("1:{:?}",a);
  let b = Fraction::new(2,4).to_string();
  println!("2:{:?}",b);
  let c = Fraction::new(36,4).to_string();
  println!("3:{:?}",c);
  let d = (Fraction::new(2,4) + Fraction::new(3,8)).to_string();
  println!("4:{:?}",d);
  let e = (Fraction::new(2,4) - Fraction::new(7,3)).to_string();
  println!("5:{:?}",e);
  let f = (Fraction::new(2,4) * Fraction::new(7,3)).to_string();
  println!("6:{:?}",f);
  let g = (Fraction::new(2,4) / Fraction::new(7,3)).to_string();
  println!("7:{:?}",g);
  let h = (Fraction::new(3,4).powf(3)).to_string();
  println!("8:{:?}",h);

 }
