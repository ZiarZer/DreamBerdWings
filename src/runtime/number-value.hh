#pragma once

#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class NumberValue : public Value {
  public:
    explicit NumberValue(float value);
    NumberValue(const NumberValue&) = delete;
    NumberValue& operator=(const NumberValue&) = delete;

    float value_get() const;
    bool is_truthy(void) const override;

    void accept(Visitor& v) const override;

  protected:
    float value_;
  };
} // namespace runtime

#include "number-value.hxx"
