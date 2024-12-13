#pragma once

#include "punctuation.hh"

namespace ast {
  inline const char Punctuation::type_get() const {
    return type_;
  }
  inline void Punctuation::type_set(const char type) {
    type_ = type;
  }

  inline const int Punctuation::count_get() const {
    return count_;
  }
  inline void Punctuation::count_set(const int count) {
    count_ = count;
  }
} // namespace ast
