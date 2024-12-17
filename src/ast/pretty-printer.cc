#include "pretty-printer.hh"
#include "all.hh"

namespace ast {
  PrettyPrinter::PrettyPrinter(std::ostream& stream)
    : Visitor()
    , stream_(stream) {}

  void PrettyPrinter::operator()(const NullExp&) {
    stream_ << "null";
  }

  void PrettyPrinter::operator()(const NumberExp& e) {
    stream_ << e.value_get();
  }
  void PrettyPrinter::operator()(const BinaryOpExp& e) {
    e.left_get()->accept(*this);
    stream_ << str(e.operation_get());
    e.right_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const ExpInstruction& e) {
    e.expression_get()->accept(*this);
    e.punctuation_get()->accept(*this);
    stream_ << "\n";
  }

  void PrettyPrinter::operator()(const CompoundStatement& e) {
    stream_ << "{\n";
    for (Statement* statement : *(e.statements_get())) {
      statement->accept(*this);
    }
    stream_ << "}" << std::endl;
  }

  void PrettyPrinter::operator()(const UndefinedExp&) {
    stream_ << "undefined";
  }

  void PrettyPrinter::operator()(const Punctuation& e) {
    if (e.type_get() == '!' && e.count_get() < 0) {
      for (int i = 0; i > e.count_get(); i--) {
        stream_ << "¡";
      }
    } else {
      stream_ << std::string(e.count_get(), e.type_get());
    }
  }

  std::ostream& operator<<(std::ostream& stream, const Ast& tree) {
    PrettyPrinter print(stream);
    print(tree);
    return stream;
  }
} // namespace ast
