#include "evaluator.hh"

namespace runtime {
  Evaluator::Evaluator(void)
    : ast::Visitor()
    , current_value_(nullptr) {}

  runtime::Value* Evaluator::evaluate(Ast* e) const {
    e->accept((*(ast::Visitor*)this));
    return current_value_;
  }

  void Evaluator::operator()(const NullExp&) {
    current_value_ = new NullValue();
  }

  void Evaluator::operator()(const NumberExp& e) {
    current_value_ = new NumberValue(e.value_get());
  }

  void Evaluator::operator()(const StringExp& e) {
    current_value_ = new StringValue(e.value_get());
  }

  void Evaluator::operator()(const UndefinedExp&) {
    current_value_ = new UndefinedValue();
  }

  void Evaluator::operator()(const BinaryOpExp& e) {}

  void Evaluator::operator()(const UnaryOpExp& e) {}

  void Evaluator::operator()(const ArrayExp& e) {}

  void Evaluator::operator()(const ObjectExp& e) {
    std::map<std::string, Value*> final_keyvalues = std::map<std::string, Value*>();

    auto keyvalues = e.keyvalues_get();
    for (auto it = keyvalues->begin(); it != keyvalues->end(); it++) {
      final_keyvalues[it->first] = evaluate(it->second);
    }

    current_value_ = new ObjectValue(final_keyvalues);
  }

  void Evaluator::operator()(const ExpStatement& e) {
    e.expression_get()->accept(*this);
  }

  void Evaluator::operator()(const VarDecStatement& e) {}

  void Evaluator::operator()(const FunDecStatement& e) {}

  void Evaluator::operator()(const CompoundStatement& e) {}

  void Evaluator::operator()(const IfStatement& e) {
    Statement* else_clause = e.else_clause_get();
    if (evaluate(e.condition_get())->is_truthy()) {
      e.then_clause_get()->accept(*this);
    } else if (else_clause) {
      e.else_clause_get()->accept(*this);
    } else {
      current_value_ = new UndefinedValue();
    }
  }

  void Evaluator::operator()(const WhenStatement& e) {}

  void Evaluator::operator()(const ReverseStatement& e) {}

  void Evaluator::operator()(const DeleteStatement& e) {}

  void Evaluator::operator()(const ReturnStatement& e) {}

  void Evaluator::operator()(const EmptyStatement& e) {}

  void Evaluator::operator()(const SimpleVar& e) {}

  void Evaluator::operator()(const SubscriptVar& e) {}

  void Evaluator::operator()(const PropertyVar& e) {}

  void Evaluator::operator()(const TimeWatchVar& e) {}

  void Evaluator::operator()(const CallExp& e) {}

  void Evaluator::operator()(const VariableDec& e) {}

  void Evaluator::operator()(const GlobalConstantDec& e) {}

  void Evaluator::operator()(const FunctionDec& e) {}

  void Evaluator::operator()(const Punctuation& e) {}
} // namespace runtime
