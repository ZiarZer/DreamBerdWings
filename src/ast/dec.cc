#include "dec.hh"

namespace ast {
  Dec::Dec(const Location& location, std::string name)
    : Ast(location)
    , name_(name) {}

  void Dec::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
