#pragma once

#include "bool-value.hh"
#include "number-value.hh"
#include "string-value.hh"

namespace runtime {
  inline std::string StringValue::to_string() const {
    return value_;
  }

  inline std::string StringValue::value_get() const {
    return value_;
  }

  inline bool StringValue::is_truthy(void) const {
    return value_.length() > 0;
  }

  inline Value* StringValue::operator-() const {
    return value_.length() ? new NumberValue() : new NumberValue(0);
  }

  inline Value* StringValue::operator!() const {
    return new BoolValue(value_.length() != 0);
  }
} // namespace runtime
