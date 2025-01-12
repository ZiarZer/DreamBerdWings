#pragma once

#include <map>
#include "../ast/all.hh"
#include "../ast/visitor.hh"
#include "all.hh"
#include "value.hh"

namespace runtime {
  using namespace ast;

  class Evaluator : virtual public ast::Visitor {
  public:
    using ast::Visitor::operator();

    Evaluator(void);

    runtime::Value* current_value_get() const;
    void new_scope();
    void end_scope();
    Value* get_var(std::map<std::string, Value*>* vars_map, std::string var_name);
    Value* get_var(std::map<std::string, Value*>* vars_map, const Var* read_var);
    void set_var(std::map<std::string, Value*>* vars_map, std::string var_name, Value* value);
    void set_var(std::map<std::string, Value*>* vars_map, Var* written_var, Value* value);
    void add_builtins();

    runtime::Value* evaluate(Ast* e) const;

    void operator()(const NullExp&) override;
    void operator()(const NumberExp& e) override;
    void operator()(const BoolExp& e) override;
    void operator()(const StringExp& e) override;
    void operator()(const UnaryOpExp& e) override;
    void operator()(const BinaryOpExp& e) override;
    void operator()(const ArrayExp& e) override;
    void operator()(const ObjectExp& e) override;
    void operator()(const UndefinedExp&) override;
    void operator()(const SimpleVar& e) override;
    void operator()(const SubscriptVar& e) override;
    void operator()(const TimeWatchVar& e) override;
    void operator()(const CallExp& e) override;
    void operator()(const AssignExp& e) override;
    void operator()(const Punctuation& e) override;
    void operator()(const ExpStatement& e) override;
    void operator()(const VarDecStatement& e) override;
    void operator()(const FunDecStatement& e) override;
    void operator()(const CompoundStatement& e) override;
    void operator()(const IfStatement& e) override;
    void operator()(const WhenStatement& e) override;
    void operator()(const ReverseStatement& e) override;
    void operator()(const DeleteStatement& e) override;
    void operator()(const ReturnStatement& e) override;
    void operator()(const EmptyStatement& e) override;
    void operator()(const VariableDec& e) override;
    void operator()(const GlobalConstantDec& e) override;
    void operator()(const FunctionDec& e) override;

  protected:
    runtime::Value* current_value_;
    std::stack<std::map<std::string, Value*>*> scopes_;
    const ast::FunctionDec* current_function_;
    runtime::Value* return_value_;
  };
} // namespace runtime

#include "evaluator.hxx"
