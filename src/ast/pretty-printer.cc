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

  void PrettyPrinter::operator()(const StringExp& e) {
    stream_ << '"' << e.value_get() << '"';
  }

  void PrettyPrinter::operator()(const ArrayExp& e) {
    bool is_first_element = true;
    stream_ << '[';
    for (Exp* elem : *(e.elems_get())) {
      if (!is_first_element) {
        stream_ << ", ";
      } else {
        is_first_element = false;
      }
      elem->accept(*this);
    }
    stream_ << ']';
  }

  void PrettyPrinter::operator()(const ObjectExp& e) {
    bool is_first_keyvalue = true;
    stream_ << "{ ";
    for (std::pair<std::string, Exp*> keyvalue : *(e.keyvalues_get())) {
      if (!is_first_keyvalue) {
        stream_ << ", ";
      } else {
        is_first_keyvalue = false;
      }
      stream_ << keyvalue.first << ": ";
      keyvalue.second->accept(*this);
    }
    stream_ << " }";
  }

  void PrettyPrinter::operator()(const UnaryOpExp& e) {
    UnaryOpExp::Oper operation = e.operation_get();
    bool is_postfix = operation == UnaryOpExp::Oper::postincrement || operation == UnaryOpExp::Oper::postdecrement;
    if (!is_postfix) {
      stream_ << str(operation);
    }
    e.operand_get()->accept(*this);
    if (is_postfix) {
      stream_ << str(operation);
    }
  }

  void PrettyPrinter::operator()(const BinaryOpExp& e) {
    e.left_get()->accept(*this);
    stream_ << str(e.operation_get());
    e.right_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const AssignExp& e) {
    e.lvalue_get()->accept(*this);
    stream_ << " = ";
    e.expression_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const ExpStatement& e) {
    e.expression_get()->accept(*this);
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const VarDecStatement& e) {
    e.vardec_get()->accept(*this);
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const FunDecStatement& e) {
    e.fundec_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const CompoundStatement& e) {
    if (!e.is_root_get()) {
      stream_ << "{" << indent;
    } else {
      stream_ << "/* Parsed AST: */";
    }
    for (Statement* statement : *(e.statements_get())) {
      stream_ << iendl;
      statement->accept(*this);
    }
    if (!e.is_root_get()) {
      stream_ << unindent << iendl << "}";
    }
  }

  void PrettyPrinter::operator()(const IfStatement& e) {
    stream_ << "if (" << *(e.condition_get()) << ") " << *(e.then_clause_get());
    if (e.else_clause_get()) {
      stream_ << "else" << *(e.else_clause_get());
    }
  }

  void PrettyPrinter::operator()(const WhenStatement& e) {
    stream_ << "when (" << *(e.condition_get()) << ") " << *(e.body_get());
  }

  void PrettyPrinter::operator()(const ReturnStatement& e) {
    stream_ << "return ";
    e.expression_get()->accept(*this);
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const ReverseStatement& e) {
    stream_ << "reverse";
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const DeleteStatement& e) {
    stream_ << "delete ";
    e.deleted_get()->accept(*this);
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const EmptyStatement& e) {
    e.punctuation_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const UndefinedExp&) {
    stream_ << "undefined";
  }

  void PrettyPrinter::operator()(const BoolExp& e) {
    stream_ << (e.value_get() ? "true" : "false");
  }

  void PrettyPrinter::operator()(const SimpleVar& e) {
    stream_ << e.name_get();
  }

  void PrettyPrinter::operator()(const SubscriptVar& e) {
    e.var_get()->accept(*this);
    stream_ << "[";
    e.index_get()->accept(*this);
    stream_ << "]";
  }

  void PrettyPrinter::operator()(const TimeWatchVar& e) {
    stream_ << str(e.time_get()) << ' ';
    e.var_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const CallExp& e) {
    e.callee_get()->accept(*this);

    bool is_first_param = true;
    stream_ << '(';
    for (Exp* param : *(e.params_get())) {
      if (!is_first_param) {
        stream_ << ", ";
      } else {
        is_first_param = false;
      }
      param->accept(*this);
    }
    stream_ << ')';
  }

  void PrettyPrinter::operator()(const VariableDec& e) {
    stream_ << (e.reassignable_get() ? "var " : "const ");
    stream_ << (e.editable_get() ? "var " : "const ");
    stream_ << e.name_get();
    Exp* init = e.init_get();
    if (init) {
      stream_ << " = ";
      init->accept(*this);
    }
  }

  void PrettyPrinter::operator()(const GlobalConstantDec& e) {
    stream_ << "const const const " << e.name_get() << " = ";
    e.init_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const FunctionDec& e) {
    if (e.is_async_get()) {
      stream_ << "async ";
    }
    stream_ << "function " << e.name_get() << "(";

    bool is_first_arg = true;
    for (VariableDec* vardec : *(e.args_get())) {
      if (!is_first_arg) {
        stream_ << ", ";
      } else {
        is_first_arg = false;
      }
      stream_ << vardec->name_get();
    }

    stream_ << ") => ";
    e.body_get()->accept(*this);
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
