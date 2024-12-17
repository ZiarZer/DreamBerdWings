#include "if-statement.hh"

namespace ast {
  IfStatement::IfStatement(const Location& location, Exp* condition, Exp* then_clause, Exp* else_clause)
    : Statement(location)
    , condition_(condition)
    , then_clause_(then_clause)
    , else_clause_(else_clause) {}

  void IfStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
