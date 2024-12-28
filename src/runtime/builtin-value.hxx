#pragma once

#include "bool-value.hh"
#include "builtin-value.hh"

namespace runtime {
  inline std::string BuiltinValue::func_name_get() const {
    return func_name_;
  }

  inline std::string BuiltinValue::to_string(void) const {
    return "[Function" + func_name_ + "]";
  }

  inline bool BuiltinValue::is_truthy(void) const {
    return true;
  }

  inline Value* BuiltinValue::operator-() const {
    return new NumberValue();
  }

  inline Value* BuiltinValue::operator!() const {
    return new BoolValue(false);
  }
} // namespace runtime
