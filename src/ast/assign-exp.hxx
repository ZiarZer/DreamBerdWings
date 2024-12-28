#pragma once

#include "assign-exp.hh"

namespace ast {
  inline Var* AssignExp::lvalue_get() const {
    return lvalue_;
  }

  inline Exp* AssignExp::expression_get() const {
    return expression_;
  }
} // namespace ast
