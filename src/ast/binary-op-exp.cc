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
    default:
      return "";
    }
  }
} // namespace ast
