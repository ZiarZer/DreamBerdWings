#pragma once

#include "value.hh"

namespace runtime {
  class NumberValue : public Value {
  public:
    explicit NumberValue(float value);
    NumberValue(const NumberValue&) = delete;
    NumberValue& operator=(const NumberValue&) = delete;

    float value_get() const;

  protected:
    float value_;
  };
} // namespace runtime

#include "number-value.hxx"
