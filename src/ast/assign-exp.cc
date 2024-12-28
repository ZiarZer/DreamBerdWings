#include "assign-exp.hh"

namespace ast {
  AssignExp::AssignExp(const Location& location, Var* lvalue, Exp* expression)
    : Exp(location)
    , lvalue_(lvalue)
    , expression_(expression) {}

  void AssignExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
