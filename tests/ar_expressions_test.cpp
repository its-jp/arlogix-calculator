#include <catch2/catch_test_macros.hpp>
#include "calculator/arlogix_calculator.hpp"
#include "string.hpp"
TEST_CASE("CALCULATOR - Arithmetic Expressions (NO PARENTHESIS)", "[ar_express]"){
  arlogix::calculator::ArlogixCalculator calc;
  String exp = "4 + 3 / 3";
  REQUIRE(calc.evaluateArithmetic(exp) == 5);
  
  // exp = "5 + 5 + 6";
  // REQUIRE(calc.evaluateArithmetic(exp) == 16);

  // exp = "5*5 - 3";
  // REQUIRE(calc.evaluateArithmetic(exp) == 22);

  // exp = "5^2/3 + 2/3 ";
  // REQUIRE(calc.evaluateArithmetic(exp) == 9);
}
