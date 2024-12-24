#include "number-value.hh"

namespace runtime {
  NumberValue::NumberValue(float value)
    : Value()
    , value_(value) {}
} // namespace runtime
