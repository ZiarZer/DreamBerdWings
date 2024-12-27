#pragma once

#include "bool-value.hh"
#include "number-value.hh"

namespace runtime {
  inline bool BoolValue::value_get() const {
    return value_;
  }

  inline bool BoolValue::is_truthy(void) const {
    return value_;
  }

  inline Value* BoolValue::operator-() const {
    return new NumberValue(value_ ? -1 : 0);
  }

  inline Value* BoolValue::operator!() const {
    return new BoolValue(!value_);
  }
} // namespace runtime
