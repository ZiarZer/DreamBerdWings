#pragma once

#include "bool-value.hh"
#include "function-value.hh"

namespace runtime {
  inline const ast::FunctionDec* FunctionValue::function_dec_get() const {
    return function_dec_;
  }

  inline std::string FunctionValue::to_string(void) const {
    return "[Function " + function_dec_->name_get() + "]";
  }

  inline bool FunctionValue::is_truthy(void) const {
    return true;
  }

  inline Value* FunctionValue::operator-() const {
    return new NumberValue();
  }

  inline Value* FunctionValue::operator!() const {
    return new BoolValue(false);
  }
} // namespace runtime
