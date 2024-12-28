#include "builtin-value.hh"

namespace runtime {
  BuiltinValue::BuiltinValue(std::string func_name)
    : Value()
    , func_name_(func_name) {}

  void BuiltinValue::accept(Visitor& v) const {
    v(*this);
  }

  Value* BuiltinValue::call(std::vector<Value*> params) {
    if (func_name_ == "print") {
      for (int i = 0; i < params.size(); i++) {
        if (i != 0) {
          std::cout << ' ';
        }
        std::cout << params[i]->to_string();
      }
      std::cout << std::endl;
    }
    return new UndefinedValue();
  }
} // namespace runtime
