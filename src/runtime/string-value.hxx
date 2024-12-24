#pragma once

#include "string-value.hh"

namespace runtime {
  inline std::string StringValue::value_get() const {
    return value_;
  }
} // namespace runtime
