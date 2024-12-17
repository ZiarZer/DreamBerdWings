#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class IfStatement : public Statement {
  public:
    IfStatement(const Location& location, Exp* condition, Exp* then_clause, Exp* else_clause);
    IfStatement(const IfStatement&) = delete;
    IfStatement& operator=(const IfStatement&) = delete;

    Exp* condition_get() const;
    Exp* then_clause_get() const;
    Exp* else_clause_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* condition_;
    Exp* then_clause_;
    Exp* else_clause_;
  };
} // namespace ast

#include "if-statement.hxx"
