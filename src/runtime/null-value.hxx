#pragma once

#include "null-value.hh"

namespace runtime {
  inline bool NullValue::is_truthy(void) const {
    return false;
  }
} // namespace runtime
