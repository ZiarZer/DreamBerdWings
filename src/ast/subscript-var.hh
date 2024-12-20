#pragma once

#include "var.hh"
#include "visitor.hh"

namespace ast {
  class SubscriptVar : public Var {
  public:
    SubscriptVar(const Location& location, Var* var, Exp* index);
    SubscriptVar(const SubscriptVar&) = delete;
    SubscriptVar& operator=(const SubscriptVar&) = delete;

    Var* var_get() const;
    Exp* index_get() const;

    void accept(Visitor& v) const override;

  protected:
    Var* var_;
    Exp* index_;
  };
} // namespace ast

#include "subscript-var.hxx"
