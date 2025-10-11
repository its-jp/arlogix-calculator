#include "lib/fraction.hpp"
#include "lib/linked_list.hpp"
#include "lib/queue.hpp"
#include "lib/stack.hpp"
#include "lib/calculator/arlogix_calculator.hpp"
#include <iostream>
int main(){
  ArlogixCalculator calc;
  String expression = "(15 + 3) / 2";
  
  std::cout << "Expression: " << expression << std::endl;
  std::cout << "Result: " << calc.evaluateArithmetic(expression) << std::endl;

  expression = "5 > 3 & 5 > 2 & 5 > 1";

  std::cout << "Expression: " << expression << std::endl;
  std::cout << "Result: " << calc.evaluateLogic(expression) << std::endl;
  
  return 0;
}
