#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class ReturnStatement : public Statement {
  public:
    ReturnStatement(const Location& location, Exp* expression, Punctuation* punctuation);
    ReturnStatement(const ReturnStatement&) = delete;
    ReturnStatement& operator=(const ReturnStatement&) = delete;

    Exp* expression_get() const;
    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* expression_;
    Punctuation* punctuation_;
  };
} // namespace ast

#include "return-statement.hxx"
