#pragma once

#include "exp.hh"

namespace ast {
  class NumberExp : public Exp {
  public:
    NumberExp(const Location& location, int value);
    NumberExp(const NumberExp&) = delete;
    NumberExp& operator=(const NumberExp&) = delete;

    int value_get() const;

  protected:
    int value_;
  };
} // namespace ast

#include "number-exp.hxx"
