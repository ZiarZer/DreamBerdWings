#pragma once

#include <vector>
#include "dec.hh"
#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class FunctionDec : public Dec {
  public:
    FunctionDec(const Location& location,
                std::string name,
                std::vector<VariableDec*>* args,
                CompoundStatement* body,
                bool is_async);
    FunctionDec(const FunctionDec&) = delete;
    FunctionDec& operator=(const FunctionDec&) = delete;

    std::vector<VariableDec*>* args_get() const;
    CompoundStatement* body_get() const;
    bool is_async_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::vector<VariableDec*>* args_;
    CompoundStatement* body_;
    bool is_async_;
  };
} // namespace ast

#include "function-dec.hxx"
