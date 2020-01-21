/**
* @file <test.cpp>
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

// test.cpp : Defined for Google test for fraction class
//

#include "gtest/gtest.h"
#include "Fraction.h"

TEST(FractionTest, constructTest01) {
    Fraction f1(8, 22);
    Fraction f2(4, 11);

    ASSERT_EQ(f1, f2);
}

TEST(FractionTest, constructTest02) {
    Fraction f1(8, -22);
    Fraction f2(-4, 11);

    ASSERT_EQ(f1, f2);
}

TEST(FractionTest, equalityTest01) {
    Fraction f1(8, 22);
    Fraction f2(4, 11);

    ASSERT_EQ(f1, f2);
}

TEST(FractionTest, equalityTest02) {
    Fraction f1(8, 22);
    Fraction f2(5, 11);

    ASSERT_FALSE(f1 == f2);
}

TEST(FractionTest, inequalityTest01) {
    Fraction f1(8, 22);
    Fraction f2(5, 11);

    ASSERT_NE(f1, f2);
}

TEST(FractionTest, inequalityTest02) {
    Fraction f1(8, 22);
    Fraction f2(4, 11);

    ASSERT_FALSE(f1 != f2);
}


TEST(FractionTest, ltTest01) {
    Fraction f1(8, 22);
    Fraction f2(5, 11);

    ASSERT_LT(f1, f2);
}

TEST(FractionTest, ltTest02) {
    Fraction f1(8, 22);
    Fraction f2(5, 11);

    ASSERT_FALSE(f2 < f1);
}

TEST(FractionTest, ltTest03) {
    Fraction f1(1, 2);
    bool result = f1 < 3;
    ASSERT_TRUE(result);
}

TEST(FractionTest, ltTest04) {
    Fraction f1(1, 2);
    bool result = 3 < f1;
    ASSERT_FALSE(result);
}

TEST(FractionTest, leTest01) {
    Fraction f1(8, 22);
    Fraction f2(4, 11);

    ASSERT_LE(f1, f2);
}

TEST(FractionTest, leTest02) {
    Fraction f1(8, 22);
    Fraction f2(5, 11);

    ASSERT_FALSE(f2 < f1);
}

TEST(FractionTest, gtTest01) {
    Fraction f1(8, 22);
    Fraction f2(5, 22);

    ASSERT_GT(f1, f2);
}

TEST(FractionTest, gtTest02) {
    Fraction f1(8, 22);
    Fraction f2(10, 22);

    ASSERT_FALSE(f1 > f2);
}

TEST(FractionTest, gtTest03) {
    Fraction f1(1, 2);
    bool result = 3 > f1;
    ASSERT_TRUE(result);
}

TEST(FractionTest, gtTest04) {
    Fraction f1(1, 2);
    bool result = f1 > 3;
    ASSERT_FALSE(result);
}

TEST(FractionTest, geTest01) {
    Fraction f1(8, 22);
    Fraction f2(4, 11);

    ASSERT_GE(f1, f2);
}

TEST(FractionTest, geTest02) {
    Fraction f1(8, 22);
    Fraction f2(10, 22);

    ASSERT_FALSE(f1 > f2);
}

TEST(FractionTest, addTest01) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    Fraction expectedResult(7, 6);

    ASSERT_EQ(f1 + f2, expectedResult);
}

TEST(FractionTest, addTest02) {
    Fraction f1(1, 2);

    Fraction expectedResult(3, 2);

    ASSERT_EQ(f1 + 1, expectedResult);
    ASSERT_EQ(1 + f1, expectedResult);
}

TEST(FractionTest, addTest03) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    f2 += f1;
    Fraction expectedResult(7, 6);

    ASSERT_EQ(f2, expectedResult);
}

TEST(FractionTest, addTest04) {
    Fraction f1(1, 2);

    f1 += 1;
    Fraction expectedResult(3, 2);

    ASSERT_EQ(f1, expectedResult);
}

TEST(FractionTest, subTest01) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    Fraction expectedResult(-1, 6);

    ASSERT_EQ(f1 - f2, expectedResult);
}

TEST(FractionTest, subTest02) {
    Fraction f1(1, 2);

    Fraction expectedResult(-1, 2);

    ASSERT_EQ(f1 - 1, expectedResult);
}

TEST(FractionTest, subTest02b) {
    Fraction f1(1, 2);

    Fraction expectedResult(1, 2);

    ASSERT_EQ(1 - f1, expectedResult);
}

TEST(FractionTest, subTest03) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    f2 -= f1;
    Fraction expectedResult(1, 6);

    ASSERT_EQ(f2, expectedResult);
}

TEST(FractionTest, subTest04) {
    Fraction f1(1, 2);

    f1 -= 1;
    Fraction expectedResult(-1, 2);

    ASSERT_EQ(f1, expectedResult);
}


TEST(FractionTest, multTest01) {
    Fraction f1(1, -2);
    Fraction f2(-3, 4);

    Fraction expectedResult(3, 8);

    ASSERT_EQ(f1 * f2, expectedResult);
}

TEST(FractionTest, multTest02) {
    Fraction f1(1, -2);

    Fraction expectedResult(3, 2);

    ASSERT_EQ(f1 * -3, expectedResult);
    ASSERT_EQ(-3 * f1, expectedResult);
}

TEST(FractionTest, multTest03) {
    Fraction f1(1, -2);
    Fraction f2(-3, 4);

    f1 *= f2;
    Fraction expectedResult(3, 8);

    ASSERT_EQ(f1, expectedResult);
}

TEST(FractionTest, multTest04) {
    Fraction f1(1, -2);

    f1 *= 3;
    Fraction expectedResult(-3, 2);

    ASSERT_EQ(f1, expectedResult);
}

TEST(FractionTest, divTest01) {
    Fraction f1(1, -2);
    Fraction f2(-3, 4);

    Fraction expectedResult(2, 3);

    ASSERT_EQ(f1 / f2, expectedResult);
}

TEST(FractionTest, divTest02) {
    Fraction f1(1, -2);

    Fraction expectedResult(1, 6);

    ASSERT_EQ(f1 / -3, expectedResult);
}


TEST(FractionTest, divTest02b) {
    Fraction f1(1, -2);

    Fraction expectedResult(6, 1);

    ASSERT_EQ(-3 / f1, expectedResult);
}

TEST(FractionTest, divTest03) {
    Fraction f1(1, -2);
    Fraction f2(-3, 4);

    f1 /= f2;
    Fraction expectedResult(2, 3);

    ASSERT_EQ(f1, expectedResult);
}


TEST(FractionTest, divTest04) {
    Fraction f1(1, -2);

    f1 /= 3;
    Fraction expectedResult(-1, 6);

    ASSERT_EQ(f1, expectedResult);
}
TEST(FractionTest, osTest01) {
    Fraction f1(2, -4);
    std::stringstream ss;
    ss << f1;
    std::string expectedResult = "-1/2";

    ASSERT_EQ(ss.str(), expectedResult);
}

TEST(FractionTest, isTest01) {
    Fraction f1;
    std::istringstream si(std::string("-5/22"));
    si >> f1;
    Fraction  expectedResult(-5, 22);

    ASSERT_EQ(f1, expectedResult);
}


TEST(FractionTest, isTest02) {
    Fraction f1;
    std::istringstream si(std::string("5 /     -22"));
    si >> f1;
    Fraction  expectedResult(-5, 22);

    ASSERT_EQ(f1, expectedResult);
}