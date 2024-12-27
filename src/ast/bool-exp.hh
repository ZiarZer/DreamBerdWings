#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class BoolExp : public Exp {
  public:
    BoolExp(const Location& location, bool value);
    BoolExp(const BoolExp&) = delete;
    BoolExp& operator=(const BoolExp&) = delete;

    bool value_get() const;

    void accept(Visitor& v) const override;

  protected:
    float value_;
  };
} // namespace ast

#include "bool-exp.hxx"
