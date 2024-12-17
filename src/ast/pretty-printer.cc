#include "pretty-printer.hh"
#include "all.hh"

namespace ast {
  int PrettyPrinter::indent_level = 0;

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

  void PrettyPrinter::operator()(const ExpStatement& e) {
    e.expression_get()->accept(*this);
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const CompoundStatement& e) {
    stream_ << "{" << indent;
    for (Statement* statement : *(e.statements_get())) {
      stream_ << iendl;
      statement->accept(*this);
    }
    stream_ << unindent << iendl << "}";
  }

  void PrettyPrinter::operator()(const IfStatement& e) {
    stream_ << "if (" << *(e.condition_get()) << ") " << *(e.then_clause_get());
    if (e.else_clause_get()) {
      stream_ << "else" << *(e.else_clause_get());
    }
  }

  void PrettyPrinter::operator()(const WhileStatement& e) {
    stream_ << "while (" << *(e.condition_get()) << ") " << *(e.body_get());
  }

  void PrettyPrinter::operator()(const BreakStatement& e) {
    stream_ << "break" << *(e.punctuation_get());
  }

  void PrettyPrinter::operator()(const ContinueStatement& e) {
    stream_ << "continue" << *(e.punctuation_get());
  }

  void PrettyPrinter::operator()(const ReturnStatement& e) {
    stream_ << "return ";
    e.expression_get()->accept(*this);
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const EmptyStatement& e) {
    e.punctuation_get()->accept(*this);
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

  std::ostream& indent(std::ostream& o) {
    PrettyPrinter::indent_level += 1;
    return o;
  }

  std::ostream& unindent(std::ostream& o) {
    PrettyPrinter::indent_level -= 1;
    return o;
  }

  std::ostream& iendl(std::ostream& o) {
    o << std::endl;
    for (int i = 0; i < PrettyPrinter::indent_level; i++) {
      o << "  ";
    }
    return o;
  }
} // namespace ast
