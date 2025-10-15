#include "shunting_yard.hpp"

#include <cmath>
static bool isOperator(const char &ch);
static bool isStartGroupingSymbol(const char &ch);
static bool isEndGroupingSymbol(const char &ch);
static bool isMatchGroupingSymbol(const char &c1, const char &c2);
static bool isDigit(const char &ch);
static int precedence(const String& s);
static bool findOperator(const char &c);
static bool isRelationalOperator(const char& c);
static void eliminateGroupingSymbol(const char& c, Stack<Token>& stack, Queue<Token>& queue);
static void infixToPosfix(Queue<Token>& infixQueue);
static Queue<Token> tokenize(const String& expression);
static double calculatePosfix(Queue<Token>& queue);

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
      if(!stack.isEmpty() && precedence(stack.peek().str) >= precedence(currentToken.str)){
        Token popped = stack.pop();
        posfixQueue.enqueue(popped);
      }
      stack.push(currentToken);
    }
    if(currentToken.type == NUMBER) {
      posfixQueue.enqueue(currentToken);
    }
  }
  std::cout << "\nStack: " << stack.toString() << std::endl;
  while(!stack.isEmpty()){
    posfixQueue.enqueue(stack.pop());
  }
  // while(!posfixQueue.isEmpty()) {
  //   infixQueue.enqueue(posfixQueue.dequeue());
  // }
  return posfixQueue;
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

static int precedence(const String& s) {
  if (s == ">" || s == "<" | s == "<=" || s == ">=" || s == "==" || s == "!=")
    return 1;
  if (s == "+" || s == "-")
    return 2;
  if (s == "*" || s == "/")
    return 3;
  if (s == "^")
    return 4;
  return 0; // logical operators
}



static bool isRelationalOperator(const char& c){
  return c == '!' || c == '=' || c == '<' || c == '>' || c == '~' || c == '&' || c == '|';
} 
