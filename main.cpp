#include <calculator/arlogix_calculator.hpp>
#include <lexer/token.hpp>
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
    auto t = calc.evaluate(exp);
    if(t.type == BOOLEAN) {
        std::cout << "\nResult: " << t.str << std::endl;
        return 0;
    }
    else{
        std::cout << "\nResult: " << t.number << std::endl;
    }
    return 0;
}



static bool isRelationalExpression(const String& exp){
  
}
