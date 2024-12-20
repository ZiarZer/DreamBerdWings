#pragma once

#include "../ast/all.hh"
#include "dreamberd-scanner.hh"

namespace parse {
  class DreamBerdDriver {
  public:
    DreamBerdDriver();

    /**
    * \returns result of the parsed operation.
    */
    int parse();
    ast::Ast* ast_get() const;

    friend class DreamBerdScanner;
    friend class DreamBerdParser;

  private:
    void step_location(unsigned int loc);
    void location_next_line();

    parse::location get_location() const;

    ast::NullExp* make_NullExp(const parse::location& location) const;
    ast::NumberExp* make_NumberExp(const parse::location& location, float value) const;
    ast::StringExp* make_StringExp(const parse::location& location, std::string value) const;
    ast::AwaitExp* make_AwaitExp(const parse::location& location, ast::Exp* awaited) const;
    ast::BinaryOpExp* make_BinaryOpExp(const parse::location& location,
                                       ast::Exp* left,
                                       ast::BinaryOpExp::Oper operation,
                                       ast::Exp* right) const;
    ast::UndefinedExp* make_UndefinedExp(const parse::location& location) const;
    ast::Punctuation* make_Punctuation(const parse::location& location, char type, int count) const;
    ast::ExpStatement*
    make_ExpStatement(const parse::location& location, ast::Exp* expression, ast::Punctuation* punctuation) const;
    ast::VarDecStatement* make_VarDecStatement(const parse::location& location,
                                               ast::VariableDec* vardec,
                                               ast::Punctuation* punctuation) const;
    ast::CompoundStatement* make_CompoundStatement(const parse::location& location,
                                                   std::vector<ast::Statement*>* statements) const;

    ast::IfStatement* make_IfStatement(const parse::location& location,
                                       ast::Exp* condition,
                                       ast::Statement* then_clause,
                                       ast::Statement* else_clause) const;
    ast::IfStatement*
    make_IfStatement(const parse::location& location, ast::Exp* condition, ast::Statement* then_clause) const;
    ast::WhenStatement*
    make_WhenStatement(const parse::location& location, ast::Exp* condition, ast::Statement* body) const;
    ast::BreakStatement* make_BreakStatement(const parse::location& location, ast::Punctuation* punctuation) const;
    ast::ContinueStatement* make_ContinueStatement(const parse::location& location,
                                                   ast::Punctuation* punctuation) const;
    ast::ReturnStatement*
    make_ReturnStatement(const parse::location& location, ast::Exp* expression, ast::Punctuation* punctuation) const;
    ast::EmptyStatement* make_EmptyStatement(const parse::location& location, ast::Punctuation* punctuation) const;
    ast::VariableDec* make_VariableDec(const parse::location& location,
                                       std::string name,
                                       ast::Exp* init,
                                       bool reassignable,
                                       bool editable) const;

    template <class... T> std::vector<ast::Statement*>* make_statements(T... statements) const;

  private:
    DreamBerdScanner scanner_;
    DreamBerdParser parser_;
    parse::location location_;
    ast::Ast* ast_;
  };

} // namespace parse

#include "dreamberd-driver.hxx"
