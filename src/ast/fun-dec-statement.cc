#include "fun-dec-statement.hh"

namespace ast {
  FunDecStatement::FunDecStatement(const Location& location, FunctionDec* fundec)
    : Statement(location)
    , fundec_(fundec) {}

  void FunDecStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
