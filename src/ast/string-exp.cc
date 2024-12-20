#include "string-exp.hh"

namespace ast {
  StringExp::StringExp(const Location& location, std::string value)
    : Exp(location)
    , value_(value) {}

  void StringExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
