The code is reimplement the EE590 Homework3 problems with using Rust. Complex
number, Fraction, and Matrix methods are included in the files.

## Fraction
This section is used for testing Fraction in integer.
The tests can be run by using "cargo test" in GIT Bash command.
to_string() method is implemented to display several answers. It can be
displayed by using "cargo run" in GIT Bash command.
There are several tests:
1. Create new fractions and can be displayed fraction form.
   Fraction::new(3,8) --> "3/8"
   Fraction::new(2,4) --> "1/2"
2. Add(+): Fraction::new(2,4) + Fraction::new(3,8) --> "7/4"
3. Sub(-): Fraction::new(2,4) - Fraction::new(7,3) --> "-11/6"
4. Mul (* ):  Fraction::new(2,4) * Fraction::new(7,3) --> "7/6"
5. Div(/): Fraction::new(2,4) / Fraction::new(7,3) --> "3/14"
6. power (powf()): Fraction::new(3,4).powf(3)) --> "27/64"


## Complex
This section is used for testing Complex Number in Floating point.
The tests can be run by using "cargo test" in GIT Bash command.
to_string() method is implemented to display several answers. It can be
displayed by using "cargo run" in GIT Bash command.
There are several tests:
1. Create new complex number
   Complex::new(2.0,-2.0) --> "2-2i"
2. Add(+): Complex::new(2.0,-2.0) + Complex::new(2.0,-2.0) --> "4-4i"
3. Sub(-): Complex::new(3.0,-3.0) - Complex::new(2.0,-2.0) --> "1-1i"
4. Mul(* ): Complex::new(3.0,-3.0) * Complex::new(2.0,-2.0) --> "-12i"
5. Conjunction: Complex::new(2.0,-2.0).conj() --> "2+2i"
6. Magnitude: Complex::new(4.0,3.0).norm() -->"5"
7. Angle: Complex::new(4.0,3.0).arg()
8. Power: Complex::new(3.0,4.0).powf(3.0)
9. e_to_power: Complex::new(3.0,-3.0).exp()


## Matrix
This section is used for testing Matrix 3x3 and 2x2 in Floating point.
to_string() method is implemented to display several answers. It can be
displayed by using "cargo run" in GIT Bash command.
1. Matrix 3x3: Matrix3::new()
2. Matrix 2x2: Matrix2::new()
3. Matrix 3x3 Add,Sub,Mul;
4. Matrix 2x2 Add,Sub,Mul;
5. Matrix 3x3 determinant;
6. Matrix 2x2 determinant;
7. Matrix 2x2 ComplexNumber add;

## Compare between C++ and Rust
Rust is newer programming language than C++. Two of them are quite different for
solving a problem. Rust can contain package (looks like C++ library), which let
user easily to implement functions. Also, the useful "Cargo" manager allow people
to manage or compile the system more easily. The "Cargo" has a command input,
called "Cargo test", it can do the unit testing while you just need to put a
simple code "#[test]" in the section. Although Rust is a better language to
manage your system, the running time will be longer than that of C++ language.

## Improvement of the program
 In the future, the code can be improved for allowing users to choose their
 numerical type (i.e:integer/floating/ComplexNumber/Fraction). Also, the code can
 be more organized for people to see the results. 
