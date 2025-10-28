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
#include "shunting_yard/shunting_yard.hpp"
static Token calculatePosfix(Queue<Token>& queue);

double ArlogixCalculator::evaluate(const String &expression) {

  Stack<char> stack;
  Queue<Token> tokenizedQueue;

  //tokenizing the expression
  tokenizedQueue = Lexer::tokenize(expression); 

  if(tokenizedQueue.size() < 2){
    if(tokenizedQueue.at(0).type == NUMBER) return tokenizedQueue.at(0).number;
    else return tokenizedQueue.at(0).str == "true" ? 1 : 0;
  }


  std::cout << "====TOKENIZED: " << tokenizedQueue.toString() << '\n';
  Queue<Token> posfixQueue = ShuntingYard::toPosfix(tokenizedQueue);
  std::cout << "\n====POSFIX: " << posfixQueue.toString() << '\n';


  auto t = calculatePosfix(posfixQueue);
  if(t.type == NUMBER) return t.number;
  else{
    if(t.str == "true") return 1;
    return 0;
  }
}

static Token calculatePosfix(Queue<Token>& queue){
  Stack<Token> aux;
  while(!queue.isEmpty()){
    Token t = queue.dequeue();
    if(t.type == NUMBER || t.type == BOOLEAN) {
      aux.push(t);
    }
    else {
      Token newToken;

      Token secOperandToken = aux.pop();

      //deal with '!'
      if(t.str == "!") {
        newToken.type = BOOLEAN;
        if(secOperandToken.str == "true") newToken.str = "false";
        else if(secOperandToken.str == "false") newToken.str = "true";
        else{ throw std::runtime_error("Error: Unknown Operand"); }
        aux.push(newToken);
        continue;
      }

      //insufficient operands exception
      if(aux.isEmpty()) throw std::runtime_error("Error: Unsufficient Operands");

      Token firstOperandToken = aux.pop();

      //verify the two popped tokens if they have the same type so they can be manipulated
      if(firstOperandToken.type != secOperandToken.type) throw std::runtime_error("Error: Uncompatible Operands");

      //handles with boolean operands and operators
      if(firstOperandToken.type == BOOLEAN){
        newToken.type = BOOLEAN;
        if(t.str == "&&") newToken.str = firstOperandToken.str == "true" && secOperandToken.str == "true" ? "true" : "false";
        else if(t.str == "||") newToken.str = firstOperandToken.str == "true" || secOperandToken.str == "true" ? "true" : "false";
        else throw std::runtime_error("Error: Unknown Logical Operator");
        aux.push(newToken);
        continue;
      }

      newToken.type = NUMBER;
      if(t.str == "+") newToken.number = firstOperandToken.number + secOperandToken.number;
      else if(t.str == "-") newToken.number = firstOperandToken.number - secOperandToken.number;
      else if(t.str == "/") {if(secOperandToken.number != 0) newToken.number = firstOperandToken.number / secOperandToken.number; else throw std::runtime_error("Error: Division by Zero");}
      else if(t.str == "*") newToken.number = firstOperandToken.number * secOperandToken.number;
      else if(t.str == "^") newToken.number = pow(firstOperandToken.number, secOperandToken.number);
      else{
        newToken.type = BOOLEAN;
        if(t.str == ">") newToken.str = firstOperandToken.number > secOperandToken.number ? "true" : "false";
        else if(t.str == ">=") newToken.str = firstOperandToken.number >= secOperandToken.number ? "true" : "false";
        else if(t.str == "<=") newToken.str = firstOperandToken.number <= secOperandToken.number ? "true" : "false";
        else if(t.str == "<") newToken.str = firstOperandToken.number < secOperandToken.number ? "true" : "false";
        else if(t.str == "==") newToken.str = firstOperandToken.number == secOperandToken.number ? "true" : "false";
        else if(t.str == "!=") newToken.str = firstOperandToken.number != secOperandToken.number ? "true" : "false";
        else throw std::runtime_error("Error: Unknown Operator For Numbers");

      }
      aux.push(newToken);
    }
  }

  return aux.pop();
}
