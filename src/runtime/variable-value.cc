#include "variable-value.hh"
#include "undefined-value.hh"

namespace runtime {
  VariableValue::VariableValue(Value* init_value)
    : Value()
    , current_(init_value)
    , previous_(new UndefinedValue()) {}

  void VariableValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
