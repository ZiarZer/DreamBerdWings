#include "string-value.hh"

namespace runtime {
  StringValue::StringValue(std::string value)
    : Value()
    , value_(value) {}

  void StringValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
