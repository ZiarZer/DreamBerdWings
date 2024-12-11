#pragma once

#include "dreamberd-driver.hh"

namespace parse {
  inline ast::NullExp* DreamBerdDriver::make_NullExp(const parse::location& location) const {
    return new ast::NullExp(location);
  }

  inline ast::NumberExp* DreamBerdDriver::make_NumberExp(const parse::location& location, float value) const {
    return new ast::NumberExp(location, value);
  }

  inline ast::BinaryOpExp* DreamBerdDriver::make_BinaryOpExp(const parse::location& location,
                                                             ast::Exp* left,
                                                             ast::BinaryOpExp::Oper operation,
                                                             ast::Exp* right) const {
    return new ast::BinaryOpExp(location, left, operation, right);
  }

  inline ast::UndefinedExp* DreamBerdDriver::make_UndefinedExp(const parse::location& location) const {
    return new ast::UndefinedExp(location);
  }
} // namespace parse
