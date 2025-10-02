#include "arlogix_calculator.hpp"
#include "stack.hpp"

static bool isOperator(const char& ch);

double ArlogixCalculator::evaluate(const std::string& expression) {
  Stack<double> stack;
  std::string token;

  for(int i = 0; i < expression.size(); i++){
    if(isGroupingSymbol(expression[i])){
    }
  }
  for (char ch : expression) {
    if (ch == ' ') {
      if (!token.empty()) {
        stack.push(std::stod(token));
        token.clear();
      }
    } else if (isOperator(ch)) {
      double b = stack.pop();
      double a = stack.pop();
      double result;
      switch (ch) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': 
          if (b == 0) throw std::runtime_error("Division by zero");
          result = a / b; 
          break;
      }
      stack.push(result);
    } else {
      token += ch;
    }
  }
  if (!token.empty()) {
    stack.push(std::stod(token));
  }
  return stack.pop();
}

static bool isOperator(const char& ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static bool isGroupingSymbol(const char& ch) {
  return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}
