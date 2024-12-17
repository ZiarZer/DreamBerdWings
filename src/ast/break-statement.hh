#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class BreakStatement : public Statement {
  public:
    BreakStatement(const Location& location, Punctuation* punctuation);
    BreakStatement(const BreakStatement&) = delete;
    BreakStatement& operator=(const BreakStatement&) = delete;

    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Punctuation* punctuation_;
  };
} // namespace ast

#include "break-statement.hxx"
