#include "null-value.hh"

namespace runtime {
  NullValue::NullValue()
    : Value() {}

  void NullValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
