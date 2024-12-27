#pragma once

#include "bool-value.hh"
#include "number-value.hh"
#include "undefined-value.hh"

namespace runtime {
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
