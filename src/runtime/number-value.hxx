#pragma once

#include "number-value.hh"

namespace runtime {
  inline float NumberValue::value_get() const {
    return value_;
  }
} // namespace runtime
