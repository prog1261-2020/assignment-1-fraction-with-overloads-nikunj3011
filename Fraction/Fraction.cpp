/**
* @file <Fraction.cpp>
*
* @author  <Nikunj Rathod>
* @version <1.0>
*
* change log
* name      date
*
*
* (file, auther, version, and change log are depricated with modern source code management system)
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < Date in format >
*
*
* @section LICENSE
*  <Public>
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

// Fraction.cpp : Defined the functions for the static library.
//



#include "Fraction.h"
#include <iostream>
#include <cstdlib>
#include<algorithm>
// TODO: This is an example of a library function
void fnFraction()
{
}

// For Fraction:
int Fraction::gcd(int n, int m) {
	
	if (m== 0) return n;
	n %= m;
	return gcd(m, n);
	/*
	or
	
	return std::__gcd(m, n);

	or
	
	if (m <= n && n % m == 0) {
		return m;
	}
	else if (n < m) {
		return gcd(m, n);
	}
	else {
		return gcd(m, n % m);
	}
	*/
}
// constructor for (0/1)
Fraction::Fraction() : num(0), den(1) {
}
// constructor for denominator = 1
Fraction::Fraction(int n1) : num(n1), den(1) {
}
// constructor for setting numerator and denominator to the inputted numbers
Fraction::Fraction(int n1, int n2) {
	if (n2 == 0) {
		throw std::exception("Denominator cannot be 0");
	}
	int divisor = gcd(abs(n1), abs(n2));//absolute value means positive number of the value
	if (n2 < 0) {
		num = -(n1 / divisor);
		den = -(n2 / divisor);
	}
	else {
		num = n1 / divisor;
		den = n2 / divisor;
	}
}
// returns value of numerator
int Fraction::numerator() const {
	return num;
}
// returns value of denominator
int Fraction::denominator() const {
	return den;
}

//Functions for Unary operators:

// - operator (negative value of fraction)
Fraction Fraction :: operator-() {
	return Fraction(-num, den);
}
// ++ operator (post increment)
Fraction& Fraction :: operator++() {
	num += den;
	return *this;
}
// ++ operator (pre-increment)
Fraction Fraction :: operator++(int e) {
	Fraction f(num, den);
	num += den;
	return f;
}


//Functions for Binary operators:
// + operator
Fraction operator+ (const Fraction& n1, const Fraction& n2) {
	if (n1.denominator() == n2.denominator()) {
		return Fraction((n1.numerator() + n2.numerator()), n1.denominator());
	}
	else {
		return Fraction(((n1.numerator() * n2.denominator()) + (n2.numerator() * n1.denominator())), (n1.denominator() * n2.denominator()));
	}
}
// - operator
Fraction operator- (const Fraction& n1, const Fraction& n2) {
	if (n1.denominator() == n2.denominator()) {
		return Fraction((n1.numerator() - n2.numerator()), n1.denominator());
	}
	else {
		return Fraction(((n1.numerator() * n2.denominator()) - (n2.numerator() * n1.denominator())), (n1.denominator() * n2.denominator()));
	}
}
// * operator
Fraction operator* (const Fraction& n1, const Fraction& n2) {
	return Fraction((n1.numerator() * n2.numerator()), (n1.denominator() * n2.denominator()));
}
// / operator
Fraction operator/ (const Fraction& n1, const Fraction& n2) {
	return Fraction((n1.numerator() * n2.denominator()), (n1.denominator() * n2.numerator()));
}
// += operator
Fraction& Fraction :: operator+=(const Fraction& e) {
	Fraction f = Fraction(num, den) + e;
	num = f.num;
	den = f.den;
	return *this;
}
// -= operator
Fraction& Fraction :: operator-=(const Fraction& e) {
	Fraction f = Fraction(num, den) - e;
	num = f.num;
	den = f.den;
	return *this;
}
// *= operator
Fraction& Fraction :: operator*=(const Fraction& e) {
	Fraction f = Fraction(num, den) * e;
	num = f.num;
	den = f.den;
	return *this;
}
// /= operator
Fraction& Fraction :: operator/=(const Fraction& e) {
	Fraction f = Fraction(num, den) / e;
	num = f.num;
	den = f.den;
	return *this;
}

// < operator
bool operator<(const Fraction& n1, const Fraction& n2) {
	return (n1.numerator() * n2.denominator()) < (n2.numerator() * n1.denominator());
}
// <= operator
bool operator<=(const Fraction& n1, const Fraction& n2) {
	return (n1.numerator() * n2.denominator()) <= (n2.numerator() * n1.denominator());
}
// == operator
bool operator==(const Fraction& n1, const Fraction& n2) {
	return (n1.numerator() == n2.numerator()) && (n1.denominator() == n2.denominator());
}
// != operator
bool operator!=(const Fraction& n1, const Fraction& n2) {
	return (n1.numerator() != n2.numerator()) || (n1.denominator() != n2.denominator());
}
// >= operator
bool operator>=(const Fraction& n1, const Fraction& n2) {
	return (n1.numerator() * n2.denominator()) >= (n2.numerator() * n1.denominator());
}
// > operator
bool operator>(const Fraction& n1, const Fraction& n2) {
	return (n1.numerator() * n2.denominator()) > (n2.numerator() * n1.denominator());
}
// << operator
std::ostream& operator<<(std::ostream& out, const Fraction& e) {
	out << e.numerator() << "/" << e.denominator();
	return out;
}
// >> operator
std::istream& operator>>(std::istream& in, Fraction& fra) {

	int top, bottom;
	in >> top;
	if (in.peek() != 10) {
		char nextChar;
		in >> nextChar;
		if (nextChar == '/')
			in >> bottom;
		else
			bottom = 1;
		fra = Fraction(top, bottom);
	}
	else
		fra = Fraction(top);
	return in;
}
