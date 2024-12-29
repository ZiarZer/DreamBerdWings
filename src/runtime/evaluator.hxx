#pragma once

#include <map>
#include "evaluator.hh"
namespace runtime {
  inline Value* Evaluator::current_value_get() const {
    return current_value_;
  }

  inline Value* Evaluator::get_var_value(std::string var_name) const {
    try {
      return scopes_.top()->at(var_name);
    } catch (std::out_of_range&) {
      return new StringValue(var_name);
    }
  }

  inline void Evaluator::set_var_value(std::string var_name, Value* value) const {
    scopes_.top()->insert_or_assign(var_name, value);
  }
} // namespace runtime
