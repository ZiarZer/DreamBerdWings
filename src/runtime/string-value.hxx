#pragma once

#include "string-value.hh"

namespace runtime {
  inline std::string StringValue::value_get() const {
    return value_;
  }

  inline bool StringValue::is_truthy(void) const {
    return value_.length() > 0;
  }
} // namespace runtime
