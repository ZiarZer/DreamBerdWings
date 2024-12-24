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

  inline ast::StringExp* DreamBerdDriver::make_StringExp(const parse::location& location, std::string value) const {
    return new ast::StringExp(location, value);
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

  inline ast::SimpleVar* DreamBerdDriver::make_SimpleVar(const parse::location& location, std::string name) const {
    return new ast::SimpleVar(location, name);
  }

  inline ast::SubscriptVar*
  DreamBerdDriver::make_SubscriptVar(const parse::location& location, ast::Var* var, ast::Exp* index) const {
    return new ast::SubscriptVar(location, var, index);
  }

  inline ast::PropertyVar*
  DreamBerdDriver::make_PropertyVar(const parse::location& location, ast::Var* var, std::string property) const {
    return new ast::PropertyVar(location, var, property);
  }

  inline ast::TimeWatchVar* DreamBerdDriver::make_TimeWatchVar(const parse::location& location,
                                                               ast::Var* var,
                                                               ast::TimeWatchVar::Time time) const {
    return new ast::TimeWatchVar(location, var, time);
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

  inline ast::VarDecStatement* DreamBerdDriver::make_VarDecStatement(const parse::location& location,
                                                                     ast::VariableDec* vardec,
                                                                     ast::Punctuation* punctuation) const {
    return new ast::VarDecStatement(location, vardec, punctuation);
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

  inline ast::ReturnStatement* DreamBerdDriver::make_ReturnStatement(const parse::location& location,
                                                                     ast::Exp* expression,
                                                                     ast::Punctuation* punctuation) const {
    return new ast::ReturnStatement(location, expression, punctuation);
  }

  inline ast::DeleteStatement* DreamBerdDriver::make_DeleteStatement(const parse::location& location,
                                                                     ast::Var* deleted,
                                                                     ast::Punctuation* punctuation) const {
    return new ast::DeleteStatement(location, deleted, punctuation);
  }

  inline ast::ReverseStatement* DreamBerdDriver::make_ReverseStatement(const parse::location& location,
                                                                       ast::Punctuation* punctuation) const {
    return new ast::ReverseStatement(location, punctuation);
  }

  inline ast::EmptyStatement* DreamBerdDriver::make_EmptyStatement(const parse::location& location,
                                                                   ast::Punctuation* punctuation) const {
    return new ast::EmptyStatement(location, punctuation);
  }

  inline ast::VariableDec* DreamBerdDriver::make_VariableDec(const parse::location& location,
                                                             std::string name,
                                                             ast::Exp* init,
                                                             bool reassignable,
                                                             bool editable) const {
    return new ast::VariableDec(location, name, init, reassignable, editable);
  }

  template <class... T> inline std::vector<ast::Statement*>* DreamBerdDriver::make_statements(T... statements) const {
    return new std::vector<ast::Statement*>{statements...};
  }
} // namespace parse
