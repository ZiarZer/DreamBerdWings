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

  inline ast::AwaitExp* DreamBerdDriver::make_AwaitExp(const parse::location& location, ast::Exp* awaited) const {
    return new ast::AwaitExp(location, awaited);
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

  inline ast::ExpStatement* DreamBerdDriver::make_ExpStatement(const parse::location& location,
                                                               ast::Exp* expression,
                                                               ast::Punctuation* punctuation) const {
    return new ast::ExpStatement(location, expression, punctuation);
  }

  inline ast::CompoundStatement*
  DreamBerdDriver::make_CompoundStatement(const parse::location& location,
                                          std::vector<ast::Statement*>* statements) const {
    return new ast::CompoundStatement(location, statements);
  }

  inline ast::IfStatement* DreamBerdDriver::make_IfStatement(const parse::location& location,
                                                             ast::Exp* condition,
                                                             ast::Statement* then_clause,
                                                             ast::Statement* else_clause) const {
    return new ast::IfStatement(location, condition, then_clause, else_clause);
  }

  inline ast::IfStatement* DreamBerdDriver::make_IfStatement(const parse::location& location,
                                                             ast::Exp* condition,
                                                             ast::Statement* then_clause) const {
    return new ast::IfStatement(location, condition, then_clause, nullptr);
  }

  inline ast::WhenStatement* DreamBerdDriver::make_WhenStatement(const parse::location& location,
                                                                 ast::Exp* condition,
                                                                 ast::Statement* body) const {
    return new ast::WhenStatement(location, condition, body);
  }

  inline ast::BreakStatement* DreamBerdDriver::make_BreakStatement(const parse::location& location,
                                                                   ast::Punctuation* punctuation) const {
    return new ast::BreakStatement(location, punctuation);
  }

  inline ast::ContinueStatement* DreamBerdDriver::make_ContinueStatement(const parse::location& location,
                                                                         ast::Punctuation* punctuation) const {
    return new ast::ContinueStatement(location, punctuation);
  }

  inline ast::ReturnStatement* DreamBerdDriver::make_ReturnStatement(const parse::location& location,
                                                                     ast::Exp* expression,
                                                                     ast::Punctuation* punctuation) const {
    return new ast::ReturnStatement(location, expression, punctuation);
  }

  inline ast::EmptyStatement* DreamBerdDriver::make_EmptyStatement(const parse::location& location,
                                                                   ast::Punctuation* punctuation) const {
    return new ast::EmptyStatement(location, punctuation);
  }

  template <class... T> inline std::vector<ast::Statement*>* DreamBerdDriver::make_statements(T... statements) const {
    return new std::vector<ast::Statement*>{statements...};
  }
} // namespace parse
