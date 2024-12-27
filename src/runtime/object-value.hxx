#pragma once

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
} // namespace runtime
