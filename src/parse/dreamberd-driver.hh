#pragma once

#include "../ast/all.hh"
#include "../ast/pretty-printer.hh"
#include "../runtime/cli-printer.hh"
#include "../runtime/evaluator.hh"
#include "dreamberd-scanner.hh"

namespace parse {
  class DreamBerdDriver {
  public:
    DreamBerdDriver();

    /**
    * \returns result of the parsed operation.
    */
    int parse();

    int run_cli();

    ast::Ast* ast_get() const;

    friend class DreamBerdScanner;
    friend class DreamBerdParser;

  private:
    void step_location(unsigned int loc);
    void location_next_line();

    parse::location get_location() const;

    ast::NullExp* make_NullExp(const parse::location& location) const;
    ast::NumberExp* make_NumberExp(const parse::location& location, float value) const;
    ast::BoolExp* make_BoolExp(const parse::location& location, bool value) const;
    ast::StringExp* make_StringExp(const parse::location& location, std::string value) const;
    ast::ArrayExp* make_ArrayExp(const parse::location& location, std::vector<ast::Exp*>* elems) const;
    ast::ObjectExp* make_ObjectExp(const parse::location& location,
                                   std::vector<std::pair<std::string, ast::Exp*>>* keyvalues) const;
    ast::AwaitExp* make_AwaitExp(const parse::location& location, ast::Exp* awaited) const;
    ast::UnaryOpExp*
    make_UnaryOpExp(const parse::location& location, ast::Exp* operand, ast::UnaryOpExp::Oper operation) const;
    ast::BinaryOpExp* make_BinaryOpExp(const parse::location& location,
                                       ast::Exp* left,
                                       ast::BinaryOpExp::Oper operation,
                                       ast::Exp* right) const;
    ast::UndefinedExp* make_UndefinedExp(const parse::location& location) const;
    ast::SimpleVar* make_SimpleVar(const parse::location& location, std::string name) const;
    ast::SubscriptVar* make_SubscriptVar(const parse::location& location, ast::Var* var, ast::Exp* index) const;
    ast::TimeWatchVar*
    make_TimeWatchVar(const parse::location& location, ast::Var* var, ast::TimeWatchVar::Time time) const;
    ast::CallExp* make_CallExp(const parse::location& location, ast::Var* callee, std::vector<ast::Exp*>* params) const;
    ast::AssignExp* make_AssignExp(const parse::location& location, ast::Var* lvalue, ast::Exp* expression) const;
    ast::Punctuation* make_Punctuation(const parse::location& location, char type, int count) const;
    ast::ExpStatement*
    make_ExpStatement(const parse::location& location, ast::Exp* expression, ast::Punctuation* punctuation) const;
    ast::VarDecStatement* make_VarDecStatement(const parse::location& location,
                                               ast::VariableDec* vardec,
                                               ast::Punctuation* punctuation) const;
    ast::FunDecStatement* make_FunDecStatement(const parse::location& location, ast::FunctionDec* fundec) const;
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
    ast::ReturnStatement*
    make_ReturnStatement(const parse::location& location, ast::Exp* expression, ast::Punctuation* punctuation) const;
    ast::DeleteStatement*
    make_DeleteStatement(const parse::location& location, ast::Var* deleted, ast::Punctuation* punctuation) const;
    ast::ReverseStatement* make_ReverseStatement(const parse::location& location, ast::Punctuation* punctuation) const;
    ast::EmptyStatement* make_EmptyStatement(const parse::location& location, ast::Punctuation* punctuation) const;
    ast::VariableDec* make_VariableDec(const parse::location& location,
                                       std::string name,
                                       ast::Exp* init,
                                       bool reassignable,
                                       bool editable) const;
    ast::FunctionDec* make_FunctionDec(const parse::location& location,
                                       std::string name,
                                       std::vector<ast::VariableDec*>* args,
                                       ast::CompoundStatement* body,
                                       bool is_async) const;
    ast::GlobalConstantDec*
    make_GlobalConstantDec(const parse::location& location, std::string name, ast::Exp* init) const;

    template <class... T> std::vector<ast::Statement*>* make_statements(T... statements) const;
    template <class... T> std::vector<ast::Exp*>* make_exps(T... exps) const;
    template <class... T> std::vector<ast::VariableDec*>* make_args(T... args) const;
    template <class... T> std::vector<std::pair<std::string, ast::Exp*>>* make_keyvalues(T... keyvalues) const;

  private:
    DreamBerdScanner scanner_;
    DreamBerdParser parser_;
    parse::location location_;
    ast::Ast* ast_;
    bool terminated_;
  };

} // namespace parse

#include "dreamberd-driver.hxx"
