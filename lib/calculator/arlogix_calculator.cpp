#include "arlogix_calculator.hpp"
#include "token.hpp"
#include "../stack.hpp"
#include "../queue.hpp"
#include "../string.hpp"
#include <iostream>
#include <stdlib.h>
#include <cmath>

static bool isOperator(const char &ch);
static bool isStartGroupingSymbol(const char &ch);
static bool isEndGroupingSymbol(const char &ch);
static bool isMatchGroupingSymbol(const char &c1, const char &c2);
static bool isDigit(const char &ch);
static int precedence(const char &op);
static bool findOperator(const char &c);
static bool isRelationalOperator(const char &c);
static void eliminateGroupingSymbol(const char& c, Stack<char>& stack);

static double calculatePosfix(Queue<Token> queue);
double ArlogixCalculator::evaluateArithmetic(const String &expression) {
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
      else if(precedence(stack.peek()) >= precedence(expression[i])){
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
  return calculatePosfix(queue);

  // return queue.dequeue().number;
}

bool ArlogixCalculator::evaluateLogic(const String& expression){
  //TODO: need to add precedenceLogic order for every posfix generated, such as the other relational operators!
  Queue<Token> queue;
  String infix;
  for(int i = 0; i < expression.size(); i++){

    while(!isRelationalOperator(expression[i])) {
      infix += expression[i];
      i++;
    }
    Token evaluatedToken;
    evaluatedToken.type = NUMBER;
    evaluatedToken.number = evaluateArithmetic(infix);
    infix.clear();
    queue.enqueue(evaluatedToken);

    Token t;
    t.type = OPERATOR;
    t.op = expression[i];
  }
  return false;
}

static double calculatePosfix(Queue<Token> queue){
  Stack<Token> aux;
  while(!queue.isEmpty()){
    Token t = queue.dequeue();
    if(!(t.type == OPERATOR)) aux.push(t);
    else {
      Token secOperandToken = aux.pop();
      Token firstOperandToken = aux.pop();

      Token newToken;
      newToken.type = NUMBER;
      switch(t.op){
        case '+': newToken.number = firstOperandToken.number + secOperandToken.number; break;
        case '-': newToken.number = firstOperandToken.number - secOperandToken.number; break;
        case '/': newToken.number = firstOperandToken.number / secOperandToken.number; break;
        case '*': newToken.number = firstOperandToken.number * secOperandToken.number; break;
        case '^': newToken.number = pow(firstOperandToken.number, secOperandToken.number); break;
        default: break;
      }

      aux.push(newToken);
    }
  }

  return aux.pop().number;
}


static void eliminateGroupingSymbol(const char &c, Stack<char> &stack){
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

static int precedence(const char &op) {
  if(op == '>' || op == '<' || op == '=' || op == '!')
    return 1;
  if (op == '+' || op == '-' || isStartGroupingSymbol(op))
    return 2;
  if (op == '*' || op == '/')
    return 3;
  if (op == '^')
    return 4;
  return 0; //NOTE: returns 0 if it is a logic operator! (|, &, n)
}


static bool isRelationalOperator(const char &c){
  return c == '!' || c == '=' || c == '<' || c == '>';
}
