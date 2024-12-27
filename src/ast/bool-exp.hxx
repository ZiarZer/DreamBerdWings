#pragma once

#include "bool-exp.hh"

namespace ast {
  inline bool BoolExp::value_get() const {
    return value_;
  }
} // namespace ast
