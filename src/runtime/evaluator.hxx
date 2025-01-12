#pragma once

#include <map>
#include "evaluator.hh"

namespace runtime {
  inline Value* Evaluator::current_value_get() const {
    return current_value_;
  }
} // namespace runtime
