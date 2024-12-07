#pragma once

#include "binary-op-exp.hh"

namespace ast {
  inline BinaryOpExp::Oper BinaryOpExp::operation_get() const {
    return operation_;
  }

  inline Exp* BinaryOpExp::left_get() const {
    return left_;
  }

  inline Exp* BinaryOpExp::right_get() const {
    return right_;
  }
} // namespace ast
