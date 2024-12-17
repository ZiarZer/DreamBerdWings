#pragma once

#include "while-statement.hh"

namespace ast {
  inline Exp* WhileStatement::condition_get() const {
    return condition_;
  }

  inline Statement* WhileStatement::body_get() const {
    return body_;
  }
} // namespace ast
