#include "arlogix_calculator.hpp"
#include "token.hpp"
#include "../stack.hpp"
#include "../queue.hpp"
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
static Queue<Token> infixToPosfix(Queue<Token>& infixQueue);
static Queue<Token> tokenize(const String& expression);
// static double calculatePosfix(Queue<Token>& queue);

double ArlogixCalculator::evaluateArithmetic(const String &expression) {

  // if(expression.size() < 3) return atof(expression.c_str());
  Stack<char> stack;
  Queue<Token> tokenizedQueue;
  Queue<Token> posfixQueue;
  String token;
  int i = 0;

  //tokenizing the expression
  tokenizedQueue = tokenize(expression); 
  posfixQueue = infixToPosfix(tokenizedQueue);
  std::cout << "Tokenized Expression: " << tokenizedQueue.toString() << std::endl;


  // return calculatePosfix(queue);

}

// bool ArlogixCalculator::evaluateLogic(const String& expression){
//   //TODO: need to add precedenceLogic order for every posfix generated, such as the other relational operators!
//   Queue<Token> queue;
//   Stack<char> stack;
//   String posfix;
//   int i = 0;
//   while(i < expression.size()){
//
//     while(!isRelationalOperator(expression[i]) && expression[i] != '\0') {
//       posfix += expression[i];
//       i++;
//     }
//     if(!posfix.empty()){
//       Token evaluatedToken;
//       evaluatedToken.type = NUMBER;
//       evaluatedToken.number = evaluateArithmetic(posfix);
//       queue.enqueue(evaluatedToken);
//       posfix.clear();
//     }
//
//     if(!stack.isEmpty() && precedence(stack.peek()) >= precedence(expression[i])) {
//       char popped = stack.pop();
//       if(popped == '\0' || popped == ' ') continue;
//       Token t;
//       t.type = OPERATOR;
//       t.op = popped;
//       queue.enqueue(t);
//       stack.push(expression[i]);
//     }
//     else{
//       stack.push(expression[i]);
//     }
//     i++;
//   }
//   while(!stack.isEmpty()){
//
//     char popped = stack.pop();
//     if(popped == '\0' || popped == ' ') continue;
//     Token t;
//     t.type = OPERATOR;
//     t.op = popped;
//     queue.enqueue(t);
//   }
//   std::cout << queue.toString() << std::endl;
//   return calculatePosfix(queue);
// }
//
// static double calculatePosfix(Queue<Token>& queue){
//   Stack<Token> aux;
//   while(!queue.isEmpty()){
//     Token t = queue.dequeue();
//     if(t.type == NUMBER) {
//       aux.push(t);
//     }
//     else {
//       Token secOperandToken = aux.pop();
//       Token firstOperandToken = aux.pop();
//
//       Token newToken;
//       newToken.type = NUMBER;
//       switch(t.str){
//         case '+': newToken.number = firstOperandToken.number + secOperandToken.number; break;
//         case '-': newToken.number = firstOperandToken.number - secOperandToken.number; break;
//         case '/': newToken.number = firstOperandToken.number / secOperandToken.number; break;
//         case '*': newToken.number = firstOperandToken.number * secOperandToken.number; break;
//         case '^': newToken.number = pow(firstOperandToken.number, secOperandToken.number); break;
//         case '>': newToken.number = firstOperandToken.number > secOperandToken.number; break;
//         case '<': newToken.number = firstOperandToken.number < secOperandToken.number; break;
//         case '&': newToken.number = (firstOperandToken.number != 0) && (secOperandToken.number != 0); break;
//         case '|': newToken.number = (firstOperandToken.number != 0) || (secOperandToken.number != 0); break;
//         case '=': newToken.number = (firstOperandToken.number != 0) == (secOperandToken.number != 0); break;
//         case '!': newToken.number = (firstOperandToken.number != 0) != (secOperandToken.number != 0); break;
//
//         default:
//           throw std::runtime_error("Error: Unknown Operator");
//       }
//
//       aux.push(newToken);
//     }
//   }
//
//   return aux.pop().number;
// }

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
    new (&t.str) String(String::to_string(stack.pop()));
    queue.enqueue(t);
  }
}

static Queue<Token> tokenize(const String& expression) {
  Queue<Token> queue;
  String token;
  int i = 0;
  while(i < expression.size()){
    while(i < expression.size() && (isDigit(expression[i]) || expression[i] == '.')) {
      token += expression[i++];
    }
    if(!token.empty()){
      Token t;
      t.type = NUMBER;
      t.number = atof(token.c_str());
      queue.enqueue(t);
      token.clear();
    } 
    while(i < expression.size() && isOperator(expression[i])) { 
      token += expression[i++];
    }
    if(!token.empty()){
      Token t;
      t.type = OPERATOR;
      t.str = token;
      queue.enqueue(t);
      token.clear();
    }
    if(i < expression.size() && isStartGroupingSymbol(expression[i])){
      Token t;
      t.type = PARENTHESIS;
      new (&t.str) String(String::to_string(expression[i]));
      queue.enqueue(t);
    }
    if(i < expression.size() && isEndGroupingSymbol(expression[i])){
      Token t;
      t.type = PARENTHESIS;
      new (&t.str) String(String::to_string(expression[i]));
      queue.enqueue(t);
    }
    i++;
  }
  return queue;
}

static Queue<Token> infixToPosfix(Queue<Token>& infixQueue) {
  Queue<Token> posfixQueue;
  String token;
  int i = 0;
  while(infixQueue.size() > 0) {
    Token currentToken = infixQueue.dequeue();
  }
  while(i < expression.size()){
    while(i < expression.size() && (isDigit(expression[i]) || expression[i] == '.')) {
      token += expression[i++];
    }
    if(!token.empty()){
      Token t;
      t.type = NUMBER;
      t.number = atof(token.c_str());
      queue.enqueue(t);
      token.clear();
    } 
    while(i < expression.size() && isOperator(expression[i])) { 
      token += expression[i++];
    }
    if(!token.empty()){
      Token t;
      t.type = OPERATOR;
      t.str = token;
      queue.enqueue(t);
      token.clear();
    }
    if(i < expression.size() && isStartGroupingSymbol(expression[i])){
      Token t;
      t.type = PARENTHESIS;
      new (&t.str) String(String::to_string(expression[i]));
      queue.enqueue(t);
    }
    if(i < expression.size() && isEndGroupingSymbol(expression[i])){
      Token t;
      t.type = PARENTHESIS;
      new (&t.str) String(String::to_string(expression[i]));
      queue.enqueue(t);
    }
    i++;
  }
  return queue;
}
static bool isOperator(const char &ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == '=' || ch == '<' || ch == '>';
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
  return c == '!' || c == '=' || c == '<' || c == '>' || c == '=' || c == '&' || c == '|' || c == '~';
} 
