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
static void eliminateGroupingSymbol(const char& c, Stack<char>& stack, Queue<Token>& queue);

static double calculatePosfix(Queue<Token>& queue);
double ArlogixCalculator::evaluateArithmetic(const String &expression) {
  Stack<char> stack;
  Queue<Token> queue;
  String token;
  char prevToken;

  int i = 0;
  while(i < expression.size()){
    while(isDigit(expression[i]) || expression[i] == '.') {
      token += expression[i++];
    }
    if(!token.empty()){
      Token t;
      t.type = NUMBER;
      t.number = atof(token.c_str());
      queue.enqueue(t);
      token.clear();
    }
    

    if(isStartGroupingSymbol(expression[i])){
       stack.push(expression[i]);
    }
    if(isOperator(expression[i])){
      if(!stack.isEmpty() && precedence(stack.peek()) >= precedence(expression[i])) {
        char popped = stack.pop();
        Token t;
        t.type = OPERATOR;
        t.op = popped;
        queue.enqueue(t);
       }
      stack.push(expression[i]);
    }
    if(isEndGroupingSymbol(expression[i])){
      std::cout << stack.toString() << '\n';
      eliminateGroupingSymbol(expression[i], stack, queue);
    }
    std::cout << "=====STACK====" << '\n';
    std::cout << stack.toString() << '\n';
    std::cout << "==============" << '\n';
    i++;
  }

  // for (int i = 0; i < expression.size(); i++) {
  //   while (isDigit(expression[i]) || expression[i] == '.') {
  //     token += expression[i++];
  //   }
  //   if (!token.empty()) {
  //     double num = atof(token.c_str());
  //     Token t;
  //     t.type = NUMBER;
  //     t.number = num;
  //     queue.enqueue(t);
  //     token.clear();
  //   }
  //   else if(isOperator(expression[i])) {
  //     while(!stack.isEmpty() && isOperator(stack.peek()) &&
  //         precedence(stack.peek()) >= precedence(expression[i])) {
  //          char popped = stack.pop();
  //         Token t;
  //         t.type = OPERATOR;
  //         t.op = popped;
  //         queue.enqueue(t);
  //     }
  //     stack.push(expression[i]);
  //   }
  //   else if(isStartGroupingSymbol(expression[i])) {
  //     stack.push(expression[i]); 
  //   }
  //   else if(isEndGroupingSymbol(expression[i])){
  //     eliminateGroupingSymbol(expression[i], stack, queue); 
  //   }

  // }
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

static double calculatePosfix(Queue<Token>& queue){
  Stack<Token> aux;
  std::cout << queue.toString() << '\n';
  while(!queue.isEmpty()){
    Token t = queue.dequeue();
    if(t.type == NUMBER) {
      aux.push(t);
    }
    else {
      // std::cout << aux.toString() << '\n';
      Token secOperandToken = aux.pop();
      // std::cout << aux.toString() << '\n';
      Token firstOperandToken = aux.pop();
      // std::cout << aux.toString() << '\n';

      Token newToken;
      newToken.type = NUMBER;
      switch(t.op){
        case '+': newToken.number = firstOperandToken.number + secOperandToken.number; break;
        case '-': newToken.number = firstOperandToken.number - secOperandToken.number; break;
        case '/': newToken.number = firstOperandToken.number / secOperandToken.number; break;
        case '*': newToken.number = firstOperandToken.number * secOperandToken.number; break;
        case '^': newToken.number = pow(firstOperandToken.number, secOperandToken.number); break;
        default:
          throw std::runtime_error("Error: Unknown Operator");
      }

      aux.push(newToken);
    }
  }

  // std::cout << aux.toString() << '\n';
  // if (aux.size() != 1){
  return aux.pop().number;
}


static void eliminateGroupingSymbol(const char &c, Stack<char> &stack, Queue<Token> &queue){
  Stack<char> aux;

  while(!stack.isEmpty() && !isStartGroupingSymbol(stack.peek())){
    aux.push(stack.pop());
  }

  if(!stack.isEmpty() && isStartGroupingSymbol(stack.peek())){
    stack.pop();
  }
  while(!aux.isEmpty()){
    Token t;
    t.type = OPERATOR;
    t.op = aux.pop();
    queue.enqueue(t);
  }

  // while(!aux.isEmpty()){
  //   stack.push(aux.pop());
  // }
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
  if (op == '+' || op == '-')
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
