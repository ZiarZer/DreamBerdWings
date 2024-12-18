#include "await-exp.hh"

namespace ast {
  AwaitExp::AwaitExp(const Location& location, Exp* awaited)
    : Exp(location)
    , awaited_(awaited) {}

  void AwaitExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
