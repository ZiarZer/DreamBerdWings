#include "number-value.hh"

namespace runtime {
  NumberValue::NumberValue(float value)
    : Value()
    , value_(value) {}

  void NumberValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
