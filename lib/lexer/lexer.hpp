#pragma once
#include "token.hpp"
#include "structures/queue.hpp"
#include "structures/stack.hpp"

namespace Lexer {
  Queue<Token> tokenize(const String& expression);
}

