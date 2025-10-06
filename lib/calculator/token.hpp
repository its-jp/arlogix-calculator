#pragma once
#include <ostream>


enum TokenType {NUMBER, OPERATOR};

struct Token {
  TokenType type;
  union {
    double number;
    char op;
  };
};
