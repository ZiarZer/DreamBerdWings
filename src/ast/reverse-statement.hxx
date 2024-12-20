#pragma once

#include "reverse-statement.hh"

namespace ast {
  inline Punctuation* ReverseStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
