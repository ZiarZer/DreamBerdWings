#include "evaluator.hh"

namespace runtime {
  Evaluator::Evaluator(void)
    : ast::Visitor()
    , current_value_(nullptr)
    , current_function_(nullptr)
    , return_value_(nullptr) {
    variables_ = std::map<std::string, Value*>();
    variables_["print"] = new BuiltinValue("print");
  }

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

  void Evaluator::operator()(const BoolExp& e) {
    current_value_ = new BoolValue(e.value_get());
  }

  void Evaluator::operator()(const StringExp& e) {
    current_value_ = new StringValue(e.value_get());
  }

  void Evaluator::operator()(const UndefinedExp&) {
    current_value_ = new UndefinedValue();
  }

  void Evaluator::operator()(const BinaryOpExp& e) {}

  void Evaluator::operator()(const UnaryOpExp& e) {
    switch (e.operation_get()) {
    case UnaryOpExp::Oper::minus:
      current_value_ = -*evaluate(e.operand_get());
      break;
    case UnaryOpExp::Oper::_not:
      current_value_ = !*evaluate(e.operand_get());
      break;
    case UnaryOpExp::Oper::preincrement:
      // TODO: increment operand
      current_value_ = evaluate(e.operand_get());
      break;
    case UnaryOpExp::Oper::predecrement:
      // TODO: decrement operand
      current_value_ = evaluate(e.operand_get());
      break;
    case UnaryOpExp::Oper::postincrement:
      current_value_ = evaluate(e.operand_get());
      // TODO: increment operand
      break;
    case UnaryOpExp::Oper::postdecrement:
      current_value_ = evaluate(e.operand_get());
      // TODO: decrement operand
      break;
    }
  }

  void Evaluator::operator()(const ArrayExp& e) {
    std::vector<Value*> values = std::vector<Value*>();

    for (ast::Exp* elem : *(e.elems_get())) {
      values.push_back(evaluate(elem));
    }

    current_value_ = new ObjectValue(values);
  }

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

  void Evaluator::operator()(const VarDecStatement& e) {
    e.vardec_get()->accept(*this);
  }

  void Evaluator::operator()(const FunDecStatement& e) {
    e.fundec_get()->accept(*this);
  }

  void Evaluator::operator()(const CompoundStatement& e) {
    for (Statement* statement : *(e.statements_get())) {
      statement->accept(*this);
      if (return_value_) {
        if (current_function_) {
          return_value_ = nullptr; // Reset
          return;
        } else {
          // TODO error: return outside of function
        }
      }
    }

    // Functions with no return statement returns undefined
    if (current_function_) {
      current_value_ = new UndefinedValue();
    }
  }

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

  void Evaluator::operator()(const ReturnStatement& e) {
    if (!current_function_) {
      throw new std::domain_error("return outside of function");
    } else {
      return_value_ = evaluate(e.expression_get());
      current_value_ = return_value_;
    }
  }

  void Evaluator::operator()(const EmptyStatement& e) {}

  void Evaluator::operator()(const SimpleVar& e) {
    Value* variable_value = variables_[e.name_get()];
    current_value_ = variable_value ? variable_value : new StringValue(e.name_get());
  }

  void Evaluator::operator()(const SubscriptVar& e) {}

  void Evaluator::operator()(const PropertyVar& e) {
    ObjectValue* main_var_value = dynamic_cast<ObjectValue*>(evaluate(e.var_get()));
    if (!main_var_value) {
      current_value_ = new UndefinedValue();
    } else {
      auto properties = main_var_value->properties_get();
      try {
        current_value_ = properties[e.property_get()];
      } catch (const std::out_of_range& e) {
        current_value_ = new UndefinedValue();
      }
    }
  }

  void Evaluator::operator()(const TimeWatchVar& e) {}

  void Evaluator::operator()(const CallExp& e) {
    Value* callee_value = evaluate(e.callee_get());
    FunctionValue* function_value = dynamic_cast<FunctionValue*>(callee_value);
    if (function_value) {
      // TODO: add scopes
      int param_index = 0;
      auto fundec = function_value->function_dec_get();
      auto args = fundec->args_get();
      auto params = e.params_get();

      for (VariableDec* vardec : *args) {
        Exp* param = (param_index < args->size()) ? (*params)[param_index++] : new UndefinedExp(e.location_get());
        evaluate(new VariableDec(vardec->location_get(), vardec->name_get(), param, true, true));
      }

      current_function_ = fundec;
      return_value_ = nullptr;
      fundec->body_get()->accept(*this);
    } else {
      BuiltinValue* builtin_value = dynamic_cast<BuiltinValue*>(callee_value);
      auto params_values = std::vector<Value*>();
      for (Exp* param : *e.params_get()) {
        params_values.push_back(evaluate(param));
      }
      current_value_ = builtin_value ? builtin_value->call(params_values) : new UndefinedValue();
    }
  }

  void Evaluator::operator()(const VariableDec& e) {
    Exp* init = e.init_get();
    variables_[e.name_get()] = init ? evaluate(init) : new UndefinedValue();
    current_value_ = new UndefinedValue();
  }

  void Evaluator::operator()(const GlobalConstantDec& e) {}

  void Evaluator::operator()(const FunctionDec& e) {
    variables_[e.name_get()] = new FunctionValue(&e);
    current_value_ = new UndefinedValue();
  }

  void Evaluator::operator()(const Punctuation& e) {}
} // namespace runtime
