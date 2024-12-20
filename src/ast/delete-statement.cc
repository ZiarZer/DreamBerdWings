#include "delete-statement.hh"

namespace ast {
  DeleteStatement::DeleteStatement(const Location& location, Punctuation* punctuation)
    : Statement(location)
    , punctuation_(punctuation) {}

  void DeleteStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
