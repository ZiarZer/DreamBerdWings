#pragma once

#include "value.hh"

namespace runtime {
  class NullValue : public Value {
  public:
    explicit NullValue();
    NullValue(const NullValue&) = delete;
    NullValue& operator=(const NullValue&) = delete;
  };
} // namespace runtime
