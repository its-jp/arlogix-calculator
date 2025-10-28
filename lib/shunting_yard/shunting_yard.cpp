#include "shunting_yard.hpp"

#include <cmath>
#include <stdexcept>
static bool isOperator(const char &ch);
static bool isStartGroupingSymbol(const char &ch);
static bool isEndGroupingSymbol(const char &ch);
static bool isMatchGroupingSymbol(const char &c1, const char &c2);
static int precedence(const String& s);
static bool findOperator(const char &c);
static bool isRelationalOperator(const char& c);
static void eliminateGroupingSymbol(const char& c, Stack<Token>& stack, Queue<Token>& queue);
static void infixToPosfix(Queue<Token>& infixQueue);
static Queue<Token> tokenize(const String& expression);

Queue<Token> ShuntingYard::toPosfix(Queue<Token>& infixQueue) {
  Queue<Token> posfixQueue;
  Stack<Token> stack;
  while(!infixQueue.isEmpty()){
    Token currentToken = infixQueue.dequeue();
    if(currentToken.type == PARENTHESIS){
      if(isStartGroupingSymbol(currentToken.str[0])){
        stack.push(currentToken);
      }
      if(isEndGroupingSymbol(currentToken.str[0])){
        eliminateGroupingSymbol(currentToken.str[0], stack, posfixQueue);
      }
    }
    if(currentToken.type == OPERATOR) {
      while(!stack.isEmpty() && stack.peek().type == OPERATOR){

        int currentPrecedence = precedence(currentToken.str);
        int stackPrecedence = precedence(stack.peek().str);
        
        bool isRightAssociative = currentToken.str == "^";
        if((!isRightAssociative && stackPrecedence >= currentPrecedence) || (isRightAssociative && stackPrecedence > currentPrecedence)){
          Token popped = stack.pop();
          posfixQueue.enqueue(popped);
        }
        else{
          break;
        }
      }
      stack.push(currentToken);
    }
    if(currentToken.type == NUMBER || currentToken.type == BOOLEAN) {
      posfixQueue.enqueue(currentToken);
    }
  }
  while(!stack.isEmpty()){
    auto currentToken = stack.pop();
    if(isStartGroupingSymbol(currentToken.str[0]) || isEndGroupingSymbol(currentToken.str[0]))
      throw std::runtime_error("Error: Unbalanced Grouping Symbol");
    posfixQueue.enqueue(currentToken);
  }
  return posfixQueue;
}

static void eliminateGroupingSymbol(const char &c, Stack<Token> &stack, Queue<Token> &queue){
  Stack<Token> aux;

  while(!stack.isEmpty() && !isStartGroupingSymbol(stack.peek().str[0])){
    aux.push(stack.pop());
  }

  if(!stack.isEmpty() && isStartGroupingSymbol(stack.peek().str[0])){
    stack.pop();
  }
  while(!aux.isEmpty()){
    Token t(aux.pop().str, OPERATOR);
    t.type = OPERATOR;
    queue.enqueue(t);
  }
}
static bool isOperator(const char &ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == '=' || ch == '<' || ch == '>';
}


static bool isStartGroupingSymbol(const char &ch) {
  return ch == '(' || ch == '[' || ch == '{';
}

static bool isEndGroupingSymbol(const char &ch) {
   return ch == '}' || ch == ')' || ch == ']';
}

static bool isMatchGroupingSymbol(const char &c1, const char &c2){
  return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
}

static int precedence(const String& s) {
  if (s == "!" )
    return 6;
  if (s == "^")
    return 5;
  if (s == "*" || s == "/")
    return 4;
  if (s == "+" || s == "-")
    return 3;
  if (s == ">" || s == "<" || s == "<=" || s == ">=" || s == "==" || s == "!=")
    return 2;
  if (s == "&&")
    return 1;
  if (s == "||")
    return 0;
  return -1; // unknown or invalid
}



static bool isRelationalOperator(const char& c){
  return c == '!' || c == '=' || c == '<' || c == '>' || c == '~' || c == '&' || c == '|';
} 
