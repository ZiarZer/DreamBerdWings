#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class EmptyStatement : public Statement {
  public:
    EmptyStatement(const Location& location, Punctuation* punctuation);
    EmptyStatement(const EmptyStatement&) = delete;
    EmptyStatement& operator=(const EmptyStatement&) = delete;

    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Punctuation* punctuation_;
  };
} // namespace ast

#include "empty-statement.hxx"
