#pragma once
#include "string/string.hpp"
enum TokenType {NUMBER, OPERATOR, PARENTHESIS};

struct Token {
  TokenType type;
  double number;
  String str;
  Token() {
      number = 0.0;
      str = "";
  }

  Token(double num) : number(num), type(NUMBER) {}
    
  Token(const String& s, TokenType ttype) : str(s), type(ttype){};

};
