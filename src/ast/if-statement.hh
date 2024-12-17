#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class IfStatement : public Statement {
  public:
    IfStatement(const Location& location, Exp* condition, Statement* then_clause, Statement* else_clause);
    IfStatement(const IfStatement&) = delete;
    IfStatement& operator=(const IfStatement&) = delete;

    Exp* condition_get() const;
    Statement* then_clause_get() const;
    Statement* else_clause_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* condition_;
    Statement* then_clause_;
    Statement* else_clause_;
  };
} // namespace ast

#include "if-statement.hxx"
