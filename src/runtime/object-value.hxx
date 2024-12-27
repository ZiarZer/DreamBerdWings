#pragma once

#include "bool-value.hh"
#include "number-value.hh"
#include "object-value.hh"

namespace runtime {
  inline std::map<std::string, Value*> ObjectValue::properties_get() const {
    return properties_;
  }

  inline bool ObjectValue::is_truthy(void) const {
    return true;
  }

  inline bool ObjectValue::is_array_get() const {
    return is_array_;
  }

  inline Value* ObjectValue::operator-() const {
    return is_array_ && properties_.empty() ? new NumberValue(0) : new NumberValue();
  }

  inline Value* ObjectValue::operator!() const {
    return new BoolValue(false);
  }
} // namespace runtime
