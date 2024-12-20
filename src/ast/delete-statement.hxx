#pragma once

#include "delete-statement.hh"

namespace ast {
  inline Punctuation* DeleteStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
