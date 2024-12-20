#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class ReverseStatement : public Statement {
  public:
    ReverseStatement(const Location& location, Punctuation* punctuation);
    ReverseStatement(const ReverseStatement&) = delete;
    ReverseStatement& operator=(const ReverseStatement&) = delete;

    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Punctuation* punctuation_;
  };
} // namespace ast

#include "reverse-statement.hxx"
