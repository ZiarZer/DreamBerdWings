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
    void operator()(const BinaryOpExp& e) override;
    void operator()(const UndefinedExp&) override;
    void operator()(const Punctuation& e) override;
    void operator()(const ExpStatement& e) override;
    void operator()(const CompoundStatement& e) override;

  protected:
    std::ostream& stream_;
  };

  std::ostream& indent(std::ostream& o);
  std::ostream& unindent(std::ostream& o);
  std::ostream& iendl(std::ostream& o);
  std::ostream& operator<<(std::ostream& ostr, const Ast& tree);
} // namespace ast
