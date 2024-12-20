#include "reverse-statement.hh"

namespace ast {
  ReverseStatement::ReverseStatement(const Location& location, Punctuation* punctuation)
    : Statement(location)
    , punctuation_(punctuation) {}

  void ReverseStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
