#pragma once

#include "dreamberd-driver.hh"

namespace parse {
  inline ast::Ast* DreamBerdDriver::ast_get() const {
    return ast_;
  }

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

  inline ast::Punctuation*
  DreamBerdDriver::make_Punctuation(const parse::location& location, char type, int count) const {
    return new ast::Punctuation(location, type, count);
  }

  inline ast::CompoundStatement*
  DreamBerdDriver::make_CompoundStatement(const parse::location& location,
                                          std::vector<ast::Statement*>* statements) const {
    return new ast::CompoundStatement(location, statements);
  }

  template <class... T> inline std::vector<ast::Statement*>* DreamBerdDriver::make_statements(T... statements) const {
    return new std::vector<ast::Statement*>{statements...};
  }
} // namespace parse
