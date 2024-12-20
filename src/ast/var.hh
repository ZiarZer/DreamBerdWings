#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class Var : public Exp {
  public:
    Var(const Location& location);
    Var(const Var&) = delete;
    Var& operator=(const Var&) = delete;
  };
} // namespace ast
