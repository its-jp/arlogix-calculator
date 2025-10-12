#pragma once
#include "../string.hpp"
namespace arlogix::calculator{
  class ArlogixCalculator {
    public:
      ArlogixCalculator() = default;
      double evaluateArithmetic(const String& expression);
      bool evaluateLogic(const String& expression);
  };
}
