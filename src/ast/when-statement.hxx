#pragma once

#include "when-statement.hh"

namespace ast {
  inline Exp* WhenStatement::condition_get() const {
    return condition_;
  }

  inline Statement* WhenStatement::body_get() const {
    return body_;
  }
} // namespace ast
