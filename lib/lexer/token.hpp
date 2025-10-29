#pragma once
#include <string/string.hpp>
enum TokenType {NUMBER, OPERATOR, PARENTHESIS, BOOLEAN};

struct Token {
  TokenType type;
  double number;
  String str;
  Token() {
      number = 0.0;
      str = "";
  }

  Token(const String& s, double num, TokenType ttype) : str(s), number(num), type(ttype) {}

  Token(double num) : number(num), type(NUMBER) {}
    
  Token(const String& s, TokenType ttype) : str(s), type(ttype){};

};
