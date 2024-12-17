#pragma once

#include "empty-statement.hh"

namespace ast {
  inline Punctuation* EmptyStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
