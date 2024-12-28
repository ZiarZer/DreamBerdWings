#pragma once

#include "bool-value.hh"
#include "null-value.hh"
#include "number-value.hh"

namespace runtime {
  inline std::string NullValue::to_string() const {
    return "null";
  }

  inline bool NullValue::is_truthy(void) const {
    return false;
  }

  inline Value* NullValue::operator-() const {
    return new NumberValue(0);
  }

  inline Value* NullValue::operator!() const {
    return new BoolValue(true);
  }
} // namespace runtime
