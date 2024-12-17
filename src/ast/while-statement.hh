#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class WhileStatement : public Statement {
  public:
    WhileStatement(const Location& location, Exp* condition, Statement* body);
    WhileStatement(const WhileStatement&) = delete;
    WhileStatement& operator=(const WhileStatement&) = delete;

    Exp* condition_get() const;
    Statement* body_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* condition_;
    Statement* body_;
  };
} // namespace ast

#include "while-statement.hxx"
