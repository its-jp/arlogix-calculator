#pragma once
#include <string/string.hpp>
#include <lexer/token.hpp>

class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    Token evaluate(const String& expression);
};
