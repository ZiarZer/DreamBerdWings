#include "return-statement.hh"

namespace ast {
  ReturnStatement::ReturnStatement(const Location& location, Exp* expression, Punctuation* punctuation)
    : Statement(location)
    , expression_(expression)
    , punctuation_(punctuation) {}

  void ReturnStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
