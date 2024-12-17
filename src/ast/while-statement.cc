#include "while-statement.hh"

namespace ast {
  WhileStatement::WhileStatement(const Location& location, Exp* condition, Statement* body)
    : Statement(location)
    , condition_(condition)
    , body_(body) {}

  void WhileStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
