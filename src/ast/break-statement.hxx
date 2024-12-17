#pragma once

#include "break-statement.hh"

namespace ast {
  inline Punctuation* BreakStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
