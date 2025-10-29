#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <iostream>
#include <calculator/arlogix_calculator.hpp>
#include <string/string.hpp>

using Catch::Approx;
TEST_CASE("CALCULATOR - Arithmetic Expressions (NO PARENTHESIS)", "[ar_express]") {
  ArlogixCalculator calc;
  double res;
  String exp;

  SECTION("Basic operations") {
    exp = "4 + 3 / 3";
    res = calc.evaluate(exp).number;
    REQUIRE(res == 5);
    std::cout << "RESULT: " << res << std::endl;

    exp = "5 + 5 + 6";
    REQUIRE(calc.evaluate(exp).number == 16);

    exp = "5*5 - 3"; 
    REQUIRE(calc.evaluate(exp).number == 22);

    exp = "5^2/3 + 2/ 3";
    res = calc.evaluate(exp).number;
    REQUIRE(res == 9);
    std::cout << "RESULT: " << res << std::endl;

    exp = "55+55";
    REQUIRE(calc.evaluate(exp).number == 110);
  }

  SECTION("Operator precedence") {
    exp = "2 + 3 * 4"; // 2 + 12 = 14
    REQUIRE(calc.evaluate(exp).number == 14);

    exp = "10 - 6 / 3"; // 10 - 2 = 8
    REQUIRE(calc.evaluate(exp).number == 8);

    exp = "2 + 3 * 4 - 5"; // 2 + 12 - 5 = 9
    REQUIRE(calc.evaluate(exp).number == 9);

    exp = "10 - 2 * 3 + 4"; // 10 - 6 + 4 = 8
    REQUIRE(calc.evaluate(exp).number == 8);
  }

  SECTION("Exponents and mixed operations") {
    exp = "2^3 + 4*2"; // 8 + 8 = 16
    REQUIRE(calc.evaluate(exp).number == 16);

    exp = "3 + 2^3 * 2"; // 3 + 8*2 = 19
    REQUIRE(calc.evaluate(exp).number == 19);

    exp = "2^3^2"; // 2^(3^2) = 512 -> right association!
    REQUIRE(calc.evaluate(exp).number == 512);
  }

  SECTION("Decimal numbers") {
    exp = "2.5 + 3.5";
    REQUIRE(calc.evaluate(exp).number == Approx(6.0));

    exp = "10.5 - 2.25 * 2";
    REQUIRE(calc.evaluate(exp).number == Approx(6.0));

    exp = "5.5 / 2";
    REQUIRE(calc.evaluate(exp).number == Approx(2.75));
  }

  SECTION("Negative numbers and unary minus") {
    exp = "-5 + 3";
    REQUIRE(calc.evaluate(exp).number == -2);

    exp = "-5 * 2";
    REQUIRE(calc.evaluate(exp).number == -10);

    exp = "-2^3"; // interpreted as -(2^3) = -8
    REQUIRE(calc.evaluate(exp).number == -8);

    exp = "2    -   3  ";
    REQUIRE(calc.evaluate(exp).number == -1);

    exp = "-2  - 3 * 2"; // -2 + (-6) = -8
    REQUIRE(calc.evaluate(exp).number == -8);
  }

  SECTION("Spacing variations") {
    exp = "   2+3* 4 ";
    REQUIRE(calc.evaluate(exp).number == 14);

    exp = "10-   5   +2";
    REQUIRE(calc.evaluate(exp).number == 7);

    exp = "  5  *  2  +  1  ";
    REQUIRE(calc.evaluate(exp).number == 11);
  }

  SECTION("Large numbers") {
    exp = "1000000 + 2000000";
    REQUIRE(calc.evaluate(exp).number == 3000000);

    exp = "999999 * 2";
    REQUIRE(calc.evaluate(exp).number == 1999998);
  }
}

