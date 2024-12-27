#pragma once

#include "visitor.hh"

namespace runtime {
  class BoolValue : public Value {
  public:
    explicit BoolValue(bool value);
    BoolValue(const BoolValue&) = delete;
    BoolValue& operator=(const BoolValue&) = delete;

    bool value_get() const;
    bool is_truthy(void) const override;

    void accept(Visitor& v) const override;

  protected:
    bool value_;
  };
} // namespace runtime

#include "bool-value.hxx"
