#pragma once

#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class NullValue : public Value {
  public:
    explicit NullValue();
    NullValue(const NullValue&) = delete;
    NullValue& operator=(const NullValue&) = delete;

    void accept(Visitor& v) const override;
  };
} // namespace runtime
