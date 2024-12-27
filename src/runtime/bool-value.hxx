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
} // namespace runtime
