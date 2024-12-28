#include "binary-op-exp.hh"

namespace ast {
  BinaryOpExp::BinaryOpExp(const Location& location, Exp* left, BinaryOpExp::Oper operation, Exp* right)
    : Exp(location)
    , left_(left)
    , operation_(operation)
    , right_(right) {}

  std::string str(BinaryOpExp::Oper operation) {
    switch (operation) {
    case BinaryOpExp::Oper::add:
      return "+";
    case BinaryOpExp::Oper::sub:
      return "-";
    case BinaryOpExp::Oper::mul:
      return "*";
    case BinaryOpExp::Oper::div:
      return "/";
    case BinaryOpExp::Oper::pow:
      return "^";
    case BinaryOpExp::Oper::lt:
      return "<";
    case BinaryOpExp::Oper::leq:
      return "<=";
    case BinaryOpExp::Oper::gt:
      return ">";
    case BinaryOpExp::Oper::geq:
      return ">=";
    case BinaryOpExp::Oper::eq:
      return "==";
    case BinaryOpExp::Oper::preciseeq:
      return "===";
    case BinaryOpExp::Oper::issame:
      return "====";
    default:
      return "";
    }
  }

  void BinaryOpExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
