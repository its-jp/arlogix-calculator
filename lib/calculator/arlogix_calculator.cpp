#include "arlogix_calculator.hpp"
#include "stack.hpp"
#include <stdlib.h>

using namespace std;

static bool isOperator(const char& ch);
static bool isGroupingSymbol(const char& ch);

double ArlogixCalculator::evaluate(const String& expression) {
  Stack<double> stack;
  String token;

  for(int i = 0; i < expression.size(); i++){
    if(isGroupingSymbol(expression[i])){
    }
  }

  for (int i = 0; i < expression.size(); i++) {
    char ch = expression[i];
    if (ch == ' ') {
      if (!token.empty()) {
        stack.push(atol(token.c_str()));
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
    stack.push(atol(token.c_str()));
  }
  return stack.pop();
}

static bool isOperator(const char& ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static bool isGroupingSymbol(const char& ch) {
  return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}
