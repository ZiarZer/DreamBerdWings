#include "break-statement.hh"

namespace ast {
  BreakStatement::BreakStatement(const Location& location, Punctuation* punctuation)
    : Statement(location)
    , punctuation_(punctuation) {}

  void BreakStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
