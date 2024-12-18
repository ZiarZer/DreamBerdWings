#include "when-statement.hh"

namespace ast {
  WhenStatement::WhenStatement(const Location& location, Exp* condition, Statement* body)
    : Statement(location)
    , condition_(condition)
    , body_(body) {}

  void WhenStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
