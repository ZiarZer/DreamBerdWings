#pragma once

#include "visitor.hh"

namespace ast {
  class PrettyPrinter : virtual public Visitor {
  public:
    static int indent_level;

    using Visitor::operator();

    PrettyPrinter(std::ostream& stream);

    void operator()(const NullExp&) override;
    void operator()(const NumberExp& e) override;
    void operator()(const BoolExp& e) override;
    void operator()(const StringExp& e) override;
    void operator()(const ArrayExp& e) override;
    void operator()(const ObjectExp& e) override;
    void operator()(const UnaryOpExp& e) override;
    void operator()(const BinaryOpExp& e) override;
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
    void operator()(const ReturnStatement& e) override;
    void operator()(const ReverseStatement& e) override;
    void operator()(const DeleteStatement& e) override;
    void operator()(const EmptyStatement& e) override;
    void operator()(const VariableDec& e) override;
    void operator()(const GlobalConstantDec& e) override;
    void operator()(const FunctionDec& e) override;

  protected:
    std::ostream& stream_;
  };

  std::ostream& indent(std::ostream& o);
  std::ostream& unindent(std::ostream& o);
  std::ostream& iendl(std::ostream& o);
  std::ostream& operator<<(std::ostream& ostr, const Ast& tree);
} // namespace ast
