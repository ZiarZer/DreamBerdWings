#pragma once

#include "fun-dec-statement.hh"

namespace ast {
  inline FunctionDec* FunDecStatement::fundec_get() const {
    return fundec_;
  }
} // namespace ast
