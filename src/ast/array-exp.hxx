#pragma once

#include "array-exp.hh"

namespace ast {
  inline std::vector<Exp*>* ArrayExp::elems_get() const {
    return elems_;
  }
} // namespace ast
