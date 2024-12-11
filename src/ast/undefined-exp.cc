#include "undefined-exp.hh"

namespace ast {
  UndefinedExp::UndefinedExp(const Location& location)
    : Exp(location) {}

  void UndefinedExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
