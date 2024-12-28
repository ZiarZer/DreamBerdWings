#pragma once

#include "bool-value.hh"
#include "number-value.hh"
#include "undefined-value.hh"

namespace runtime {
  inline std::string UndefinedValue::to_string() const {
    return "undefined";
  }

  inline bool UndefinedValue::is_truthy(void) const {
    return false;
  }

  inline Value* UndefinedValue::operator-() const {
    return new NumberValue();
  }

  inline Value* UndefinedValue::operator!() const {
    return new BoolValue(true);
  }
} // namespace runtime
