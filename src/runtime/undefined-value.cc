#include "undefined-value.hh"

namespace runtime {
  UndefinedValue::UndefinedValue()
    : Value() {}

  void UndefinedValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
