#pragma once
#include "../string.hpp"
enum TokenType {NUMBER, OPERATOR, PARENTHESIS};

struct Token {
  TokenType type;
  union {
    double number;
    String str;
  };
    Token() {
        type = NUMBER;
        number = 0.0;
    }

    Token(double num) {
        type = NUMBER;
        number = num;
    }

    // Token(const String& s) {
    //     type = OPERATOR;
    //     new (&str) String(s); 
    // }

    Token(const Token& other) {
        type = other.type;
        if (type == NUMBER)
            number = other.number;
        else
            new (&str) String(other.str);
    }

    Token& operator=(const Token& other) {
        if (this == &other) return *this;

        if (type == OPERATOR)
            str.~String();

        type = other.type;

        if (type == NUMBER)
            number = other.number;
        else
            new (&str) String(other.str);

        return *this;
    }

    ~Token() {
        if (type == OPERATOR)
            str.~String();
    }
};
