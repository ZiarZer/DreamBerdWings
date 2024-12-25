#pragma once

#include "call-exp.hh"

namespace ast {
  inline Var* CallExp::callee_get() const {
    return callee_;
  }

  inline std::vector<Exp*>* CallExp::params_get() const {
    return params_;
  }
} // namespace ast
