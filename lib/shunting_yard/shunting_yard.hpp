#pragma once

#include "lexer/token.hpp"
#include "structures/stack.hpp"
#include "structures/queue.hpp"

namespace ShuntingYard {
  Queue<Token> toPosfix(Queue<Token>& infix);
}
