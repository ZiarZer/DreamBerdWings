#pragma once

#include "evaluator.hh"

namespace runtime {
  inline Value* Evaluator::current_value_get() const {
    return current_value_;
  }

  inline std::map<std::string, Value*> Evaluator::variables_get() const {
    return variables_;
  }
} // namespace runtime
