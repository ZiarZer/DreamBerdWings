#include "property-var.hh"

namespace ast {
  PropertyVar::PropertyVar(const Location& location, Var* var, std::string property)
    : Var(location)
    , var_(var)
    , property_(property) {}

  void PropertyVar::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
