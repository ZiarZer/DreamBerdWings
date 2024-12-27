#pragma once

#include "undefined-value.hh"

namespace runtime {
  inline bool UndefinedValue::is_truthy(void) const {
    return false;
  }
} // namespace runtime
