#pragma once

#include "number-value.hh"

namespace runtime {
  inline float NumberValue::value_get() const {
    return value_;
  }

  inline bool NumberValue::is_truthy(void) const {
    return value_ != 0;
  }
} // namespace runtime
