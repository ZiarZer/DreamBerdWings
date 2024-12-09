#include "pretty-printer.hh"
#include "all.hh"

namespace ast {
  PrettyPrinter::PrettyPrinter(std::ostream& stream)
    : Visitor()
    , stream_(stream) {}

  void PrettyPrinter::operator()(const NumberExp& e) {
    stream_ << e.value_get();
  }
  void PrettyPrinter::operator()(const BinaryOpExp& e) {
    e.left_get()->accept(*this);
    stream_ << str(e.operation_get());
    e.right_get()->accept(*this);
  }

  std::ostream& operator<<(std::ostream& stream, const Ast& tree) {
    PrettyPrinter print(stream);
    print(tree);
    return stream;
  }
} // namespace ast
