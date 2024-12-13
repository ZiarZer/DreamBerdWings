#include "exp-statement.hh"

namespace ast {
  ExpStatement::ExpStatement(const Location& location, Exp* expression, Punctuation* punctuation)
    : Statement(location)
    , expression_(expression)
    , punctuation_(punctuation) {}

  void ExpStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
