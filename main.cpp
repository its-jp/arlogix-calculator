#include "calculator/arlogix_calculator.hpp"
#include <iostream>
#include <string/string.hpp>

static bool isRelationalExpression(const String& exp);
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "\nUse: " << argv[0] << " \"<expression>\"" << std::endl;
        return 1;
    }

    // argv[1] contains the expression
    String exp = argv[1];

    std::cout << "\nReceived Expression: " << exp << std::endl;

    ArlogixCalculator calc;
    double res = calc.evaluate(exp);
    std::cout << "\nResult: " << res << std::endl;

    return 0;
}



static bool isRelationalExpression(const String& exp){
  
}
