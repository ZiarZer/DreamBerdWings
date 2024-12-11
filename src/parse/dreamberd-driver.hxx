#pragma once

#include "dreamberd-driver.hh"

namespace parse {
  inline ast::NumberExp* DreamBerdDriver::make_NumberExp(const parse::location& location, float value) const {
    return new ast::NumberExp(location, value);
  }

  inline ast::BinaryOpExp* DreamBerdDriver::make_BinaryOpExp(const parse::location& location,
                                                             ast::Exp* left,
                                                             ast::BinaryOpExp::Oper operation,
                                                             ast::Exp* right) const {
    return new ast::BinaryOpExp(location, left, operation, right);
  }
} // namespace parse
