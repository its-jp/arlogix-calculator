#pragma once
#include <string/string.hpp>
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    Token evaluate(const String& expression);
};
