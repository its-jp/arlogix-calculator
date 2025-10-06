#pragma once
#include "../string.hpp"
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    double evaluate(const String& expression);
};
