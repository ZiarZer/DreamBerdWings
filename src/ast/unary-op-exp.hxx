#pragma once

#include "unary-op-exp.hh"

namespace ast {
  inline UnaryOpExp::Oper UnaryOpExp::operation_get() const {
    return operation_;
  }

  inline Exp* UnaryOpExp::operand_get() const {
    return operand_;
  }
} // namespace ast
