#pragma once

#include "function-dec.hh"

namespace ast {
  inline std::vector<VariableDec*>* FunctionDec::args_get() const {
    return args_;
  }

  inline Statement* FunctionDec::body_get() const {
    return body_;
  }

  inline bool FunctionDec::is_async_get() const {
    return is_async_;
  }
} // namespace ast
