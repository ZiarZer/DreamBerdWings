#pragma once

#include "return-statement.hh"

namespace ast {
  inline Exp* ReturnStatement::expression_get() const {
    return expression_;
  }

  inline Punctuation* ReturnStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
