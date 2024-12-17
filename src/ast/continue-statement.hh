#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class ContinueStatement : public Statement {
  public:
    ContinueStatement(const Location& location, Punctuation* punctuation);
    ContinueStatement(const ContinueStatement&) = delete;
    ContinueStatement& operator=(const ContinueStatement&) = delete;

    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Punctuation* punctuation_;
  };
} // namespace ast

#include "continue-statement.hxx"
