#include "subscript-var.hh"

namespace ast {
  SubscriptVar::SubscriptVar(const Location& location, Var* var, Exp* index)
    : Var(location)
    , var_(var)
    , index_(index) {}

  void SubscriptVar::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
