#include "lexer/token.hpp"
#include <lexer/lexer.hpp>

static bool isOperator(const char &ch);
static bool isStartGroupingSymbol(const char &ch);
static bool isEndGroupingSymbol(const char &ch);
static bool isMatchGroupingSymbol(const char &c1, const char &c2);
static bool isDigit(const char &ch);
static bool isRelationalOperator(const char& c);
static bool isBooleanOperand(const char& c);
Queue<Token> Lexer::tokenize(const String& expression) {
  Queue<Token> queue;
  String token;
  int i = 0;
  int lastRealCharIndex = -1;
  while(i < expression.size()){
    if(expression[i] == ' ') {i++; continue;}

    //it only checks if '-' is part of the number or should be considered as an operator between two operands
    if (expression[i] == '-' && (i == 0 || isOperator(expression[i - 1]) || isRelationalOperator(expression[lastRealCharIndex]) || isStartGroupingSymbol(expression[lastRealCharIndex]))) { 
      token += expression[i++];
      lastRealCharIndex = i - 1;
    }
    while(i < expression.size() && (isDigit(expression[i]) || expression[i] == '.')) {
      token += expression[i++];
      lastRealCharIndex = i - 1;
    }
    if(!token.empty()){
      Token t(atof(token.c_str()));
      queue.enqueue(t);
      token.clear();
      continue;
    } 
    while(i < expression.size() && isOperator(expression[i])) { 
      token += expression[i++];
      lastRealCharIndex = i - 1;
    }
    if(!token.empty()){
      Token t(token, OPERATOR);
      queue.enqueue(t);
      token.clear();
      continue;
    }

    while(i < expression.size() && isBooleanOperand(expression[i])) {
      token += expression[i++];
      lastRealCharIndex = i - 1;
    }
    if(!token.empty()){
      Token t(token, BOOLEAN);
      queue.enqueue(t);
      token.clear();
      continue;
    }
    while(i < expression.size() && isRelationalOperator(expression[i])) {
      token += expression[i++];
      lastRealCharIndex = i - 1;
    }
    if(!token.empty()){
      Token t(token, OPERATOR);
      queue.enqueue(t);
      token.clear();
      continue;
    }
    if(i < expression.size() && isStartGroupingSymbol(expression[i])){
      Token t(String::to_string(expression[i]), PARENTHESIS);
      queue.enqueue(t);
      lastRealCharIndex = i;  //lastRealCharIndex is setted to i (and not i - 1) because the i++ is at the end of the loop!
    }
    if(i < expression.size() && isEndGroupingSymbol(expression[i])){
      Token t(String::to_string(expression[i]), PARENTHESIS);
      queue.enqueue(t);
      lastRealCharIndex = i;  //lastRealCharIndex is setted to i (and not i - 1) because the i++ is at the end of the loop!
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

static bool isRelationalOperator(const char& c){
  return c == '!' || c == '=' || c == '<' || c == '>' || c == '~' || c == '&' || c == '|';
} 

static bool isBooleanOperand(const char& c){
  return c == 't' || c == 'r' || c  == 'u' || c == 'e' || c == 'f' || c == 'a' || c == 'l' || c == 's';
}
