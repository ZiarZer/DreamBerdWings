#pragma once

#include <sstream>
#include "bool-value.hh"
#include "number-value.hh"

namespace runtime {
  inline std::string NumberValue::to_string() const {
    std::ostringstream stream;
    stream << value_;
    return stream.str();
  }

  inline float NumberValue::value_get() const {
    return value_;
  }

  inline bool NumberValue::is_NaN_get() const {
    return is_NaN_;
  }

  inline bool NumberValue::is_truthy(void) const {
    return value_ != 0;
  }

  inline Value* NumberValue::operator-() const {
    return new NumberValue(-value_);
  }

  inline Value* NumberValue::operator!() const {
    return new BoolValue(!value_);
  }
} // namespace runtime
