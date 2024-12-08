#pragma once

#include "ast.hh"
#include "fwd.hh"

namespace ast {
  class Exp : public Ast {
  public:
    explicit Exp(const Location& location);
    Exp(const Exp&) = delete;
    Exp& operator=(const Exp&) = delete;

    void accept(Visitor& v) const override = 0;
  };
} // namespace ast
