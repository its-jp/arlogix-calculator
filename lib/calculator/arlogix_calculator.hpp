#pragma once
#include <string>
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    double evaluate(const std::string& expression);
};
