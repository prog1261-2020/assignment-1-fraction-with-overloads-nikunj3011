/**
* @file <Fraction.h>
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
// Fraction.h : Defined for fraction class
//
#pragma once
#include <iostream>
#include <string>

class Fraction {
public:
	Fraction(); // constructor for (0/1)
	Fraction(int); // constructor for denominator = 1
	Fraction(int, int); // constructor for setting numerator and denominator to the inputted numbers

	int numerator() const; // returns value of numerator
	int denominator() const; // returns value of denominator

	//Functions for Unary operators:
	Fraction operator-(); // - operator (negative value of fraction)
	Fraction& operator++(); // ++ operator (post increment)
	Fraction operator++(int); // ++ operator (pre-increment)

	//Functions for Binary operators:
	friend Fraction operator+(const Fraction& n1, const Fraction& n2); // + operator
	friend Fraction operator-(const Fraction& n1, const Fraction& n2); // - operator
	friend Fraction operator*(const Fraction& n1, const Fraction& n2); // * operator
	friend Fraction operator/(const Fraction& n1, const Fraction& n2); // / operator

	Fraction& operator+=(const Fraction& e); // += operator
	Fraction& operator-=(const Fraction& e); // -= operator
	Fraction& operator*=(const Fraction& e); // *= operator
	Fraction& operator/=(const Fraction& e); // /= operator

	friend bool operator<(const Fraction& n1, const Fraction& n2); // < comparison operator
	friend bool operator<=(const Fraction& n1, const Fraction& n2); // <= comparison operator
	friend bool operator==(const Fraction& n1, const Fraction& n2); // == comparison operator
	friend bool operator!=(const Fraction& n1, const Fraction& n2); // != comparison operator
	friend bool operator>=(const Fraction& n1, const Fraction& n2); // >= comparison operator
	friend bool operator>(const Fraction& n1, const Fraction& n2); // > comparison operator

	friend std::ostream& operator<<(std::ostream& out, const Fraction& e); // << operator
	friend std::istream& operator>>(std::istream& in, Fraction& retFrac); // >> operator

private:
	int num; // numerator
	int den; // denominator
	int gcd(int, int); // greatest common divisor function
};