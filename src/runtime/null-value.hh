#pragma once

#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class NullValue : public Value {
  public:
    explicit NullValue();
    NullValue(const NullValue&) = delete;
    NullValue& operator=(const NullValue&) = delete;

    std::string to_string() const override;
    bool is_truthy(void) const override;
    Value* operator-(void) const override;
    Value* operator!(void) const override;

    void accept(Visitor& v) const override;
  };
} // namespace runtime

#include "null-value.hxx"
