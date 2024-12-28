#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class BinaryOpExp : public Exp {
  public:
    enum class Oper { add, sub, mul, div, pow, lt, leq, gt, geq, eq, preciseeq, issame };

    BinaryOpExp(const Location& location, Exp* left, Oper operation, Exp* right);
    BinaryOpExp(const BinaryOpExp&) = delete;
    BinaryOpExp& operator=(const BinaryOpExp&) = delete;

    Oper operation_get() const;
    Exp* left_get() const;
    Exp* right_get() const;

    void accept(Visitor& v) const override;

  protected:
    Oper operation_;
    Exp* left_;
    Exp* right_;
  };

  std::string str(BinaryOpExp::Oper operation);
} // namespace ast

#include "binary-op-exp.hxx"
