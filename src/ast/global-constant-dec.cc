#include "global-constant-dec.hh"

namespace ast {
  GlobalConstantDec::GlobalConstantDec(const Location& location, std::string name, Exp* init)
    : VariableDec(location, name, init, false, false) {}

  void GlobalConstantDec::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
