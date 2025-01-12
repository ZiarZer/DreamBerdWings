#pragma once

#include <sstream>
#include "bool-value.hh"
#include "variable-value.hh"

namespace runtime {
  inline void VariableValue::assign(Value* new_value) {
    current_ = new_value;
    previous_ = current_;
  }

  inline Value* VariableValue::previous_get() const {
    return previous_;
  }

  inline Value* VariableValue::current_get() const {
    return current_;
  }

  inline std::string VariableValue::to_string() const {
    return current_->to_string();
  }

  inline bool VariableValue::is_truthy(void) const {
    return current_->is_truthy();
  }

  inline Value* VariableValue::operator-() const {
    return -*current_;
  }

  inline Value* VariableValue::operator!() const {
    return !*current_;
  }
} // namespace runtime
