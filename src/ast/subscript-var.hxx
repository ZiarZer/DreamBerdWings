#pragma once

#include "subscript-var.hh"

namespace ast {
  inline Var* SubscriptVar::var_get() const {
    return var_;
  }

  inline Exp* SubscriptVar::index_get() const {
    return index_;
  }
} // namespace ast
