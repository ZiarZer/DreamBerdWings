#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class VarDecStatement : public Statement {
  public:
    VarDecStatement(const Location& location, VariableDec* vardec, Punctuation* punctuation);
    VarDecStatement(const VarDecStatement&) = delete;
    VarDecStatement& operator=(const VarDecStatement&) = delete;

    VariableDec* vardec_get() const;
    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    VariableDec* vardec_;
    Punctuation* punctuation_;
  };
} // namespace ast

#include "var-dec-statement.hxx"
