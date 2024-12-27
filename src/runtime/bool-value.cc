#include "bool-value.hh"

namespace runtime {
  BoolValue::BoolValue(bool value)
    : Value()
    , value_(value) {}

  void BoolValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
