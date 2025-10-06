#pragma once
#include "../string.hpp"
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    double evaluateArithmetic(const String& expression);
    bool evaluateLogic(const String& expression);
};
