#include "number-exp.hh"

namespace ast {
  NumberExp::NumberExp(const Location& location, float value)
    : Exp(location)
    , value_(value) {}

  void NumberExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
