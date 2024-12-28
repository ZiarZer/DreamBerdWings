#pragma once

#include "../ast/function-dec.hh"
#include "undefined-value.hh"
#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class BuiltinValue : public Value {
  public:
    explicit BuiltinValue(std::string func_name);
    BuiltinValue(const BuiltinValue&) = delete;
    BuiltinValue& operator=(const BuiltinValue&) = delete;

    std::string func_name_get() const;
    std::string to_string() const override;
    bool is_truthy(void) const override;
    Value* operator-(void) const override;
    Value* operator!(void) const override;

    void accept(Visitor& v) const override;
    Value* call(std::vector<Value*> params);

  protected:
    std::string func_name_;
  };
} // namespace runtime

#include "builtin-value.hxx"
