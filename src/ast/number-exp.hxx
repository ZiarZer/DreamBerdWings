#pragma once

#include "number-exp.hh"

namespace ast {
  inline float NumberExp::value_get() const {
    return value_;
  }
} // namespace ast
