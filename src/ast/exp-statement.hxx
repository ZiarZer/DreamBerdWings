#pragma once

#include "exp-statement.hh"

namespace ast {
  inline Exp* ExpStatement::expression_get() const {
    return expression_;
  }

  inline Punctuation* ExpStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
