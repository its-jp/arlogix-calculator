#include "lib/fraction.hpp"
#include "lib/linked_list.hpp"
#include "lib/queue.hpp"
#include "lib/stack.hpp"
#include "lib/calculator/arlogix_calculator.hpp"
#include <iostream>
int main(){
  ArlogixCalculator calc;
  std::string expression = "3 + 4 / 5";

  std::cout << "Expression: " << expression << std::endl;
  std::cout << "Result: " << calc.evaluate(expression) << std::endl;
  return 0;
}
