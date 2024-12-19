#include "var-dec-statement.hh"

namespace ast {
  VarDecStatement::VarDecStatement(const Location& location, VariableDec* vardec, Punctuation* punctuation)
    : Statement(location)
    , vardec_(vardec)
    , punctuation_(punctuation) {}

  void VarDecStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
