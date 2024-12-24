#pragma once

#include "object-value.hh"

namespace runtime {
  inline std::map<std::string, Value*> ObjectValue::properties_get() const {
    return properties_;
  }
} // namespace runtime
