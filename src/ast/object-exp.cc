#include "object-exp.hh"

namespace ast {
  ObjectExp::ObjectExp(const Location& location, std::vector<std::pair<std::string, Exp*>>* keyvalues)
    : Exp(location)
    , keyvalues_(keyvalues) {}

  void ObjectExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
