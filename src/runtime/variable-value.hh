#pragma once

#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class VariableValue : public Value {
  public:
    explicit VariableValue(Value* init_value);
    VariableValue(const VariableValue&) = delete;
    VariableValue& operator=(const VariableValue&) = delete;

    void assign(Value* new_value);
    Value* previous_get() const;
    Value* current_get() const;
    std::string to_string() const override;
    bool is_truthy(void) const override;
    Value* operator-(void) const override;
    Value* operator!(void) const override;

    void accept(Visitor& v) const override;

  protected:
    Value* previous_;
    Value* current_;
  };
} // namespace runtime

#include "variable-value.hxx"
