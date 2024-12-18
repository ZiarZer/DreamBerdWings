#include "variable-dec.hh"

namespace ast {
  VariableDec::VariableDec(const Location& location, std::string name, Exp* init, bool reassignable, bool editable)
    : Dec(location, name)
    , init_(init)
    , reassignable_(reassignable)
    , editable_(editable) {}

  void VariableDec::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
