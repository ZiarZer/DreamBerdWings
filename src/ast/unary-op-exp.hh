#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class UnaryOpExp : public Exp {
  public:
    enum class Oper { _not, minus, preincrement, predecrement, postincrement, postdecrement };

    UnaryOpExp(const Location& location, Exp* operand, Oper operation);
    UnaryOpExp(const UnaryOpExp&) = delete;
    UnaryOpExp& operator=(const UnaryOpExp&) = delete;

    Oper operation_get() const;
    Exp* operand_get() const;

    void accept(Visitor& v) const override;

  protected:
    Oper operation_;
    Exp* operand_;
  };

  std::string str(UnaryOpExp::Oper operation);
} // namespace ast

#include "unary-op-exp.hxx"
