#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class NumberExp : public Exp {
  public:
    NumberExp(const Location& location, float value);
    NumberExp(const NumberExp&) = delete;
    NumberExp& operator=(const NumberExp&) = delete;

    float value_get() const;

    void accept(Visitor& v) const override;

  protected:
    float value_;
  };
} // namespace ast

#include "number-exp.hxx"
