#include "continue-statement.hh"

namespace ast {
  ContinueStatement::ContinueStatement(const Location& location, Punctuation* punctuation)
    : Statement(location)
    , punctuation_(punctuation) {}

  void ContinueStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
