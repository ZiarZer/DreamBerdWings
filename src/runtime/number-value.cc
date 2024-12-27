#include "number-value.hh"

namespace runtime {
  NumberValue::NumberValue(float value)
    : Value()
    , value_(value)
    , is_NaN_(false) {}

  NumberValue::NumberValue()
    : Value()
    , value_(0)
    , is_NaN_(true) {}

  void NumberValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
