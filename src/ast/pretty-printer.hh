#pragma once

#include "visitor.hh"

namespace ast {
  class PrettyPrinter : virtual public Visitor {
  public:
    using Visitor::operator();

    PrettyPrinter(std::ostream& stream);

    void operator()(const NullExp&) override;
    void operator()(const NumberExp& e) override;
    void operator()(const BinaryOpExp& e) override;
    void operator()(const UndefinedExp&) override;
    void operator()(const Punctuation& e) override;

  protected:
    std::ostream& stream_;
  };

  std::ostream& operator<<(std::ostream& ostr, const Ast& tree);
} // namespace ast
