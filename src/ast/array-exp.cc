#include "array-exp.hh"

namespace ast {
  ArrayExp::ArrayExp(const Location& location, std::vector<Exp*>* elems)
    : Exp(location)
    , elems_(elems) {}

  void ArrayExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
