<<<<<<< HEAD
#include "lib/calculator/arlogix_calculator.hpp"
#include "lib/structures/queue.hpp"
#include "lib/structures/stack.hpp"
#include <iostream>
int main() {
  ArlogixCalculator calc;
  String expression = "(15 + 3) / 2";

  std::cout << "Expression: " << expression << std::endl;
  double res = calc.evaluateArithmetic(expression);
  std::cout << "Result: " << res << std::endl;

  expression = "(-1) > -3";

  std::cout << "Expression: " << expression << std::endl;
  res = calc.evaluateLogic(expression);
  std::cout << "Result: " << res << std::endl;

  return 0;
}
=======
#include <QApplication>

#include "lib/ui/ui.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  arlogix::UICalc window;
  window.show();
  return app.exec();
}
>>>>>>> origin/gui
