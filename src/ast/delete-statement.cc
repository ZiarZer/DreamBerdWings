#include "delete-statement.hh"

namespace ast {
  DeleteStatement::DeleteStatement(const Location& location, Var* deleted, Punctuation* punctuation)
    : Statement(location)
    , punctuation_(punctuation)
    , deleted_(deleted) {}

  void DeleteStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
