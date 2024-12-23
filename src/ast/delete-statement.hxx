#pragma once

#include "delete-statement.hh"

namespace ast {
  inline Punctuation* DeleteStatement::punctuation_get() const {
    return punctuation_;
  }

  inline Var* DeleteStatement::deleted_get() const {
    return deleted_;
  }
} // namespace ast
