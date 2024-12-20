#include "simple-var.hh"

namespace ast {
  SimpleVar::SimpleVar(const Location& location, std::string name)
    : Var(location)
    , name_(name) {}

  void SimpleVar::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
