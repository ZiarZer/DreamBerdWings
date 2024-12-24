#include "string-value.hh"

namespace runtime {
  StringValue::StringValue(std::string value)
    : Value()
    , value_(value) {}
} // namespace runtime
