#include "object-value.hh"

namespace runtime {
  ObjectValue::ObjectValue(std::map<std::string, Value*> properties)
    : Value()
    , properties_(properties)
    , is_array_(false) {}

  ObjectValue::ObjectValue(std::vector<Value*> elements)
    : Value()
    , properties_(std::map<std::string, Value*>())
    , is_array_(true) {
    int index = -1;
    for (Value* elem : elements) {
      properties_[std::to_string(index++)] = elem;
    }
  }

  void ObjectValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
