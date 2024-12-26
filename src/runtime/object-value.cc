#include "object-value.hh"

namespace runtime {
  ObjectValue::ObjectValue(std::map<std::string, Value*> properties)
    : Value()
    , properties_(properties) {}

  void ObjectValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
