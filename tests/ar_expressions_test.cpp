#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <calculator/arlogix_calculator.hpp>
#include <string/string.hpp>
TEST_CASE("CALCULATOR - Arithmetic Expressions (NO PARENTHESIS)", "[ar_express]"){
  ArlogixCalculator calc;
  String exp = "4 + 3 / 3";
  double res = calc.evaluateArithmetic(exp);
  REQUIRE(res == 5);
  std::cout << "RESULT: " << res << std::endl;
  
  exp = "5 + 5 + 6";
  REQUIRE(calc.evaluateArithmetic(exp) == 16);

  //FIX: problem with negative numbers! need to solve!
  // exp = "5*5 - 3"; 
  // REQUIRE(calc.evaluateArithmetic(exp) == 22);

  exp = "5 ^ 2 / 3 + 2 / 3";
  res = calc.evaluateArithmetic(exp);
  REQUIRE(calc.evaluateArithmetic(exp) == 9);
  std::cout << "RESULT: " << res << std::endl;

  exp = "55+55";
  REQUIRE(calc.evaluateArithmetic(exp) == 110);
}
