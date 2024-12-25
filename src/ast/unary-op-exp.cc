#include "unary-op-exp.hh"

namespace ast {
  UnaryOpExp::UnaryOpExp(const Location& location, Exp* operand, UnaryOpExp::Oper operation)
    : Exp(location)
    , operand_(operand)
    , operation_(operation) {}

  std::string str(UnaryOpExp::Oper operation) {
    switch (operation) {
    case UnaryOpExp::Oper::_not:
      return ";";
    case UnaryOpExp::Oper::minus:
      return "-";
    case UnaryOpExp::Oper::preincrement:
    case UnaryOpExp::Oper::postincrement:
      return "++";
    case UnaryOpExp::Oper::predecrement:
    case UnaryOpExp::Oper::postdecrement:
      return "--";
    default:
      return "";
    }
  }

  void UnaryOpExp::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
