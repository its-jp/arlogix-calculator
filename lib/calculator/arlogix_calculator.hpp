#pragma once
#include <string/string.hpp>
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    double evaluate(const String& expression);
};
