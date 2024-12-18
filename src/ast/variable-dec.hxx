#pragma once

#include "variable-dec.hh"

namespace ast {
  inline Exp* VariableDec::init_get() const {
    return init_;
  }

  inline bool VariableDec::editable_get() const {
    return editable_;
  }

  inline bool VariableDec::reassignable_get() const {
    return reassignable_;
  }
} // namespace ast
