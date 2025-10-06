#include "arlogix_calculator.hpp"
#include "calculator/token.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "string.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

static bool isOperator(const char &ch);
static bool isStartGroupingSymbol(const char &ch);
static bool isEndGroupingSymbol(const char &ch);
static bool isMatchGroupingSymbol(const char &c1, const char &c2);
static bool isDigit(const char &ch);
static int precendence(const char &op);

static void eliminateGroupingSymbol(const char& c, Stack<char>& stack);

static double calculatePosfix(Queue<Token> queue);
double ArlogixCalculator::evaluate(const String &expression) {
  Stack<char> stack;
  Queue<Token> queue;
  String token;
  char prevToken;

  for (int i = 0; i < expression.size(); i++) {
    while (isDigit(expression[i]) || expression[i] == '.') {
      token += expression[i];
      i++;
    }
    if (!token.empty()) {
      double num = atof(token.c_str());
      Token t;
      t.type = NUMBER;
      t.number = num;

      queue.enqueue(t);
      token.clear();
    }
    else if(isOperator(expression[i]) || isStartGroupingSymbol(expression[i])) {
      if(stack.isEmpty()) stack.push(expression[i]);
      else if(precendence(stack.peek()) >= precendence(expression[i])){
        char popped = stack.pop();
        Token t;
        t.type = OPERATOR;
        t.op = popped;
        queue.enqueue(t);
        stack.push(expression[i]);
      }
      else {
        stack.push(expression[i]);
      }
    }
    else if(isEndGroupingSymbol(expression[i])){
      eliminateGroupingSymbol(expression[i], stack);
    }


  }
  while(!stack.isEmpty()){
    Token t;
    t.type = OPERATOR;
    t.op = stack.pop();
    queue.enqueue(t);
  }

  std::cout << queue.toString() << '\n';
  return queue.dequeue().number;
}

static double calculatePosfix(Queue<Token> queue){
  
}


static void eliminateGroupingSymbol(const char &c, Stack<char> &stack, Queue<Token> &queue){
  Stack<char> aux;

  //TODO: need to solve why the grouping symbol is not being kicked out of the stack!
  while(!stack.isEmpty() && !isStartGroupingSymbol(stack.peek())){
    char poppedC = stack.pop();
    if(isMatchGroupingSymbol(poppedC, c)){
      continue;
    }
    aux.push(poppedC);
  }
  while(!aux.isEmpty()){
    stack.push(aux.pop());
  }
}

static bool isOperator(const char &ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

static bool isDigit(const char &ch) { return (ch >= '0' && ch <= '9'); }

static bool isStartGroupingSymbol(const char &ch) {
  return ch == '(' || ch == '[' || ch == '{';
}

static bool isEndGroupingSymbol(const char &ch) {
   return ch == '}' || ch == ')' || ch == ']';
}

static bool isMatchGroupingSymbol(const char &c1, const char &c2){
  return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
}

static int precendence(const char &op) {
  if (op == '+' || op == '-' || isStartGroupingSymbol(op))
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}
