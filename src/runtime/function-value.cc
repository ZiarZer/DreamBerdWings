#include "function-value.hh"

namespace runtime {
  FunctionValue::FunctionValue(const ast::FunctionDec* function_dec)
    : Value()
    , function_dec_(function_dec) {}

  void FunctionValue::accept(Visitor& v) const {
    v(*this);
  }
} // namespace runtime
