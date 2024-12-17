#include "empty-statement.hh"

namespace ast {
  EmptyStatement::EmptyStatement(const Location& location, Punctuation* punctuation)
    : Statement(location)
    , punctuation_(punctuation) {}

  void EmptyStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
