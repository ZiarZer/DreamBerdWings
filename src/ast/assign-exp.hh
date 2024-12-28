#pragma once

#include "var.hh"
#include "visitor.hh"

namespace ast {
  class AssignExp : public Exp {
  public:
    AssignExp(const Location& location, Var* lvalue, Exp* expression);
    AssignExp(const AssignExp&) = delete;
    AssignExp& operator=(const AssignExp&) = delete;

    Var* lvalue_get() const;
    Exp* expression_get() const;

    void accept(Visitor& v) const override;

  protected:
    Var* lvalue_;
    Exp* expression_;
  };
} // namespace ast

#include "assign-exp.hxx"
