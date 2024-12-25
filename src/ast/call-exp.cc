#include "call-exp.hh"

namespace ast {
  CallExp::CallExp(const Location& location, Var* callee, std::vector<Exp*>* params)
    : Exp(location)
    , callee_(callee)
    , params_(params) {}

  void CallExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
