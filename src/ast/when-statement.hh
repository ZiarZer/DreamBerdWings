#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class WhenStatement : public Statement {
  public:
    WhenStatement(const Location& location, Exp* condition, Statement* body);
    WhenStatement(const WhenStatement&) = delete;
    WhenStatement& operator=(const WhenStatement&) = delete;

    Exp* condition_get() const;
    Statement* body_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* condition_;
    Statement* body_;
  };
} // namespace ast

#include "when-statement.hxx"
