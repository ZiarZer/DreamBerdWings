#pragma once

#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class UndefinedValue : public Value {
  public:
    explicit UndefinedValue();
    UndefinedValue(const UndefinedValue&) = delete;
    UndefinedValue& operator=(const UndefinedValue&) = delete;

    std::string to_string() const override;
    bool is_truthy(void) const override;
    Value* operator-(void) const override;
    Value* operator!(void) const override;

    void accept(Visitor& v) const override;
  };
} // namespace runtime

#include "undefined-value.hxx"
