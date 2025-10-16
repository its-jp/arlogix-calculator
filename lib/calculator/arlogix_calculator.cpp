#include "arlogix_calculator.hpp"
#include "lexer/token.hpp"
#include "lexer/lexer.hpp"
#include "structures/stack.hpp"
#include "structures/queue.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <cmath>
<<<<<<< HEAD
#include "shunting_yard/shunting_yard.hpp"
// static bool isOperator(const char &ch);
// static bool isStartGroupingSymbol(const char &ch);
// static bool isEndGroupingSymbol(const char &ch);
// static bool isMatchGroupingSymbol(const char &c1, const char &c2);
// static bool isDigit(const char &ch);
// static int precedence(const String& s);
// static bool findOperator(const char &c);
// static bool isRelationalOperator(const char& c);
// static void eliminateGroupingSymbol(const char& c, Stack<char>& stack, Queue<Token>& queue);
// static void infixToPosfix(Queue<Token>& infixQueue);
// static Queue<Token> tokenize(const String& expression);
static double calculatePosfix(Queue<Token>& queue);

double ArlogixCalculator::evaluateArithmetic(const String &expression) {

  // if(expression.size() < 3) return atof(expression.c_str());
  Stack<char> stack;
  Queue<Token> tokenizedQueue;

  //tokenizing the expression
  tokenizedQueue = Lexer::tokenize(expression); 
  std::cout << "\nTokenized Expression: " << tokenizedQueue.toString() << std::endl;
  Queue<Token> posfixQueue = ShuntingYard::toPosfix(tokenizedQueue);
  std::cout << "\nPosfixed Expression: " << tokenizedQueue.toString() << std::endl;


  return calculatePosfix(posfixQueue);

}

bool ArlogixCalculator::evaluateLogic(const String& expression){
  //TODO: need to add precedenceLogic order for every posfix generated, such as the other relational operators!
  Queue<Token> tokenizedQueue = Lexer::tokenize(expression);
  Queue<Token> posfixQueue = ShuntingYard::toPosfix(tokenizedQueue);

  return calculatePosfix(posfixQueue);
}

static double calculatePosfix(Queue<Token>& queue){
  Stack<Token> aux;
  while(!queue.isEmpty()){
    Token t = queue.dequeue();
    if(t.type == NUMBER) {
      aux.push(t);
    }
    else {
      Token secOperandToken = aux.pop();
      Token firstOperandToken = aux.pop();

      Token newToken;
      newToken.type = NUMBER;
      if(t.str == "+") newToken.number = firstOperandToken.number + secOperandToken.number;
      else if(t.str == "-") newToken.number = firstOperandToken.number - secOperandToken.number;
      else if(t.str == "/") newToken.number = firstOperandToken.number / secOperandToken.number;
      else if(t.str == "*") newToken.number = firstOperandToken.number * secOperandToken.number;
      else if(t.str == "^") newToken.number = pow(firstOperandToken.number, secOperandToken.number);
      else if(t.str == ">") newToken.number = firstOperandToken.number > secOperandToken.number;
      else if(t.str == ">=") newToken.number = firstOperandToken.number >= secOperandToken.number;
      else if(t.str == "<=") newToken.number = firstOperandToken.number <= secOperandToken.number;
      else if(t.str == "<") newToken.number = firstOperandToken.number < secOperandToken.number;
      else if(t.str == "&&") newToken.number = (firstOperandToken.number != 0) && (secOperandToken.number != 0);
      else if(t.str == "||") newToken.number = (firstOperandToken.number != 0) || (secOperandToken.number != 0);
      else if(t.str == "==") newToken.number = (firstOperandToken.number != 0) == (secOperandToken.number != 0);
      else if(t.str == "!=") newToken.number = (firstOperandToken.number != 0) != (secOperandToken.number != 0);
      else throw std::runtime_error("Error: Unknown Operator");
      aux.push(newToken);
    }
  }

  return aux.pop().number;
}

// static void eliminateGroupingSymbol(const char &c, Stack<Token> &stack, Queue<Token> &queue){
//   Stack<Token> aux;
//
//   while(!stack.isEmpty() && !isStartGroupingSymbol(stack.peek().str[0])){
//     aux.push(stack.pop());
//   }
//
//   if(!stack.isEmpty() && isStartGroupingSymbol(stack.peek().str[0])){
//     stack.pop();
//   }
//   while(!aux.isEmpty()){
//     Token t(aux.pop().str, OPERATOR);
//     t.type = OPERATOR;
//     queue.enqueue(t);
//   }
// }
//
// static Queue<Token> tokenize(const String& expression) {
//   Queue<Token> queue;
//   String token;
//   String cleanExpression;
//   int i = 0;
//   int lastRealCharIndex = -1;
//   while(i < expression.size()){
//     if(expression[i] == ' ') {i++; continue;}
//
//     //it only checks if '-' is part of the number or should be considered as an operator between two operands
//     if (expression[i] == '-' && (i == 0 || isOperator(expression[i - 1]) || isRelationalOperator(expression[lastRealCharIndex]) || isStartGroupingSymbol(expression[lastRealCharIndex]))) { 
//       token += expression[i++];
//       lastRealCharIndex = i - 1;
//     }
//     while(i < expression.size() && (isDigit(expression[i]) || expression[i] == '.')) {
//       token += expression[i++];
//       lastRealCharIndex = i - 1;
//     }
//     if(!token.empty()){
//       Token t(atof(token.c_str()));
//       queue.enqueue(t);
//       token.clear();
//     } 
//     while(i < expression.size() && isOperator(expression[i])) { 
//       token += expression[i++];
//       lastRealCharIndex = i - 1;
//     }
//     if(!token.empty()){
//       Token t(token, OPERATOR);
//       queue.enqueue(t);
//       token.clear();
//     }
//     while(i < expression.size() && isRelationalOperator(expression[i])) {
//       token += expression[i++];
//       lastRealCharIndex = i - 1;
//     }
//     if(!token.empty()){
//       Token t(token, OPERATOR);
//       queue.enqueue(t);
//       token.clear();
//     }
//     if(i < expression.size() && isStartGroupingSymbol(expression[i])){
//       Token t(String::to_string(expression[i]), PARENTHESIS);
//       queue.enqueue(t);
//       lastRealCharIndex = i;  //lastRealCharIndex is setted to i (and not i - 1) because the i++ is at the end of the loop!
//     }
//     if(i < expression.size() && isEndGroupingSymbol(expression[i])){
//       Token t(String::to_string(expression[i]), PARENTHESIS);
//       queue.enqueue(t);
//       lastRealCharIndex = i;  //lastRealCharIndex is setted to i (and not i - 1) because the i++ is at the end of the loop!
//     }
//     i++;
//   }
//   return queue;
// }
//
// static void infixToPosfix(Queue<Token>& infixQueue) {
//   Queue<Token> posfixQueue;
//   Stack<Token> stack;
//   while(!infixQueue.isEmpty()){
//     Token currentToken = infixQueue.dequeue();
//     if(currentToken.type == PARENTHESIS){
//       if(isStartGroupingSymbol(currentToken.str[0])){
//         stack.push(currentToken);
//       }
//       if(isEndGroupingSymbol(currentToken.str[0])){
//         eliminateGroupingSymbol(currentToken.str[0], stack, posfixQueue);
//       }
//     }
//     if(currentToken.type == OPERATOR) {
//       if(!stack.isEmpty() && precedence(stack.peek().str) >= precedence(currentToken.str)){
//         Token popped = stack.pop();
//         posfixQueue.enqueue(popped);
//       }
//       stack.push(currentToken);
//     }
//     if(currentToken.type == NUMBER) {
//       posfixQueue.enqueue(currentToken);
//     }
//   }
//   std::cout << "\nStack: " << stack.toString() << std::endl;
//   while(!stack.isEmpty()){
//     posfixQueue.enqueue(stack.pop());
//   }
//   while(!posfixQueue.isEmpty()) {
//     infixQueue.enqueue(posfixQueue.dequeue());
//   }
// }
// static bool isOperator(const char &ch) {
//   return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == '=' || ch == '<' || ch == '>';
// }
//
// static bool isDigit(const char &ch) { return (ch >= '0' && ch <= '9'); }
//
// static bool isStartGroupingSymbol(const char &ch) {
//   return ch == '(' || ch == '[' || ch == '{';
// }
//
// static bool isEndGroupingSymbol(const char &ch) {
//    return ch == '}' || ch == ')' || ch == ']';
// }
//
// static bool isMatchGroupingSymbol(const char &c1, const char &c2){
//   return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
// }
//
// static int precedence(const String& s) {
//   if (s == ">" || s == "<" | s == "<=" || s == ">=" || s == "==" || s == "!=")
//     return 1;
//   if (s == "+" || s == "-")
//     return 2;
//   if (s == "*" || s == "/")
//     return 3;
//   if (s == "^")
//     return 4;
//   return 0; // logical operators
// }
//
//
//
// static bool isRelationalOperator(const char& c){
//   return c == '!' || c == '=' || c == '<' || c == '>' || c == '~' || c == '&' || c == '|';
// } 
=======

namespace arlogix::calculator{
  static bool isOperator(const char &ch);
  static bool isStartGroupingSymbol(const char &ch);
  static bool isEndGroupingSymbol(const char &ch);
  static bool isMatchGroupingSymbol(const char &c1, const char &c2);
  static bool isDigit(const char &ch);
  static int precedence(const char &op);
  static bool findOperator(const char &c);
  static bool isRelationalOperator(const char &c);
  static void eliminateGroupingSymbol(const char& c, Stack<char>& stack);

  static double calculatePosfix(Queue<Token>& queue);
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
}
>>>>>>> origin/gui
