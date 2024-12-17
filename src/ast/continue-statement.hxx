#pragma once

#include "continue-statement.hh"

namespace ast {
  inline Punctuation* ContinueStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
