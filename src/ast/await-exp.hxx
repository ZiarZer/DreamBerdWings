#pragma once

#include "await-exp.hh"

namespace ast {
  inline Exp* AwaitExp::awaited_get() const {
    return awaited_;
  }
} // namespace ast
