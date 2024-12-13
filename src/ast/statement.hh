#pragma once

#include "ast.hh"
#include "fwd.hh"

namespace ast {
  class Statement : public Ast {
  public:
    explicit Statement(const Location& location);
    Statement(const Statement&) = delete;
    Statement& operator=(const Statement&) = delete;

    void accept(Visitor& v) const override = 0;
  };
} // namespace ast
