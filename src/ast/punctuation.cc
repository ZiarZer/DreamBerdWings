#include "punctuation.hh"

namespace ast {
  Punctuation::Punctuation(const Location& location, char type, int count)
    : Ast(location)
    , type_(type)
    , count_(count) {}

  void Punctuation::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
