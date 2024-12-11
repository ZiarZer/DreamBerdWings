#include "null-exp.hh"

namespace ast {
  NullExp::NullExp(const Location& location)
    : Exp(location) {}

  void NullExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
