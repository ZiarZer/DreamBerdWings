#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class ExpStatement : public Instruction {
  public:
    ExpStatement(const Location& location, Exp* expression, Punctuation* punctuation);
    ExpStatement(const ExpStatement&) = delete;
    ExpStatement& operator=(const ExpStatement&) = delete;

    Exp* expression_get() const;
    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* expression_;
    Punctuation* punctuation_;
  };
} // namespace ast

#include "exp-statement.hxx"
