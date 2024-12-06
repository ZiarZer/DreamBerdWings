#include "number-exp.hh"

namespace ast {
  NumberExp::NumberExp(const Location& location, int value)
    : Exp(location)
    , value_(value) {}
} // namespace ast
