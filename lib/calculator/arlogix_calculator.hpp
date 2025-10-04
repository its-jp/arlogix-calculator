#pragma once
#include <string>
#include "string.hpp"
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    double evaluate(const String& expression);
};
