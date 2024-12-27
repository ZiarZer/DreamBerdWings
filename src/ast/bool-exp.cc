#include "bool-exp.hh"

namespace ast {
  BoolExp::BoolExp(const Location& location, bool value)
    : Exp(location)
    , value_(value) {}

  void BoolExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
