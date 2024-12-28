#pragma once

#include "../ast/function-dec.hh"
#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class FunctionValue : public Value {
  public:
    explicit FunctionValue(const ast::FunctionDec* function_dec);
    FunctionValue(const FunctionValue&) = delete;
    FunctionValue& operator=(const FunctionValue&) = delete;

    const ast::FunctionDec* function_dec_get() const;
    bool is_truthy(void) const override;
    Value* operator-(void) const override;
    Value* operator!(void) const override;

    void accept(Visitor& v) const override;

  protected:
    const ast::FunctionDec* function_dec_;
  };
} // namespace runtime

#include "function-value.hxx"
