#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <iostream>
#include <calculator/arlogix_calculator.hpp>
#include <string/string.hpp>
#include <lexer/token.hpp>

using Catch::Approx;

TEST_CASE("CALCULATOR - Logical Expressions (Boolean Logic)", "[lo_express]") {
  ArlogixCalculator calc;
  double res;
  String exp;

  SECTION("Basic boolean values") {
    exp = "true";
    auto t = calc.evaluate(exp);
    REQUIRE(t.str == "true");

    exp = "false";
    t = calc.evaluate(exp);
    REQUIRE(t.str == "false");
  }

  SECTION("Logical AND (&&)") {
    exp = "true && true";
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "true && false";
    REQUIRE(calc.evaluate(exp).str == "false");

    exp = "false && true";
    REQUIRE(calc.evaluate(exp).str == "false");

    exp = "false && false";
    REQUIRE(calc.evaluate(exp).str == "false");
  }

  SECTION("Logical OR (||)") {
    exp = "true || true";
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "true || false";
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "false || true";
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "false || false";
    REQUIRE(calc.evaluate(exp).str == "false");
  }

  SECTION("Logical NOT (!) and combinations") {
    exp = "!true";
    REQUIRE(calc.evaluate(exp).str == "false");

    exp = "!false";
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "!true || false"; // (false || false) = false
    REQUIRE(calc.evaluate(exp).str == "false");

    exp = "true && !false"; // (true && true) = true
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "!true && false"; // (false && false) = false
    REQUIRE(calc.evaluate(exp).str == "false");
  }

  SECTION("Mixed logical expressions") {
    exp = "true || false && false"; 
    // && has higher precedence → true || (false && false) = true
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "false && true || true"; 
    // (false && true) || true = false || true = true
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "!false && true || false";
    // (!false && true) || false = (true && true) || false = true
    REQUIRE(calc.evaluate(exp).str == "true");
  }

  SECTION("Comparison with arithmetic results") {
    exp = "3 > 2 && 5 < 10"; 
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "4 == 4 || 2 > 10"; 
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "5 != 5 || true"; // false || true = true
    REQUIRE(calc.evaluate(exp).str == "true");

    exp = "10 <= 5"; 
    REQUIRE(calc.evaluate(exp).str == "false");
  }
}

