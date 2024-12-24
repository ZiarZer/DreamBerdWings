#pragma once

#include "object-exp.hh"

namespace ast {
  inline std::vector<std::pair<std::string, Exp*>>* ObjectExp::keyvalues_get() const {
    return keyvalues_;
  }
} // namespace ast
