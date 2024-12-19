#pragma once

#include "var-dec-statement.hh"

namespace ast {
  inline VariableDec* VarDecStatement::vardec_get() const {
    return vardec_;
  }

  inline Punctuation* VarDecStatement::punctuation_get() const {
    return punctuation_;
  }
} // namespace ast
