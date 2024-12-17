#pragma once

#include "if-statement.hh"

namespace ast {
  inline Exp* IfStatement::condition_get() const {
    return condition_;
  }

  inline Exp* IfStatement::then_clause_get() const {
    return then_clause_;
  }

  inline Exp* IfStatement::else_clause_get() const {
    return else_clause_;
  }
} // namespace ast
