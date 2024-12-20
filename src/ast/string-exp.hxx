#pragma once

#include "string-exp.hh"

namespace ast {
  inline std::string StringExp::value_get() const {
    return value_;
  }
} // namespace ast
