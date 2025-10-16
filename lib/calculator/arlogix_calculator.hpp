#pragma once
<<<<<<< HEAD
#include "string/string.hpp"
class ArlogixCalculator {
  public:
    ArlogixCalculator() = default;
    double evaluateArithmetic(const String& expression);
    bool evaluateLogic(const String& expression);
};
=======
#include "../string.hpp"
namespace arlogix::calculator{
  class ArlogixCalculator {
    public:
      ArlogixCalculator() = default;
      double evaluateArithmetic(const String& expression);
      bool evaluateLogic(const String& expression);
  };
}
>>>>>>> origin/gui
