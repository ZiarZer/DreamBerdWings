#pragma once

#include "ast.hh"

namespace ast {
  class Exp : public Ast {
  public:
    explicit Exp(const Location& location);
    Exp(const Exp&) = delete;
    Exp& operator=(const Exp&) = delete;
  };
} // namespace ast
