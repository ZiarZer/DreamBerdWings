#pragma once

#include <map>
#include "evaluator.hh"

namespace runtime {
  inline Value* Evaluator::current_value_get() const {
    return current_value_;
  }

  inline Value* Evaluator::get_var(std::map<std::string, Value*>* vars_map, std::string var_name) {
    try {
      return vars_map->at(var_name);
    } catch (std::out_of_range&) {
      return new StringValue(var_name);
    }
  }

  inline Value* Evaluator::get_var(std::map<std::string, Value*>* vars_map, const Var* read_var) {
    if (const SimpleVar* simple_var = dynamic_cast<const SimpleVar*>(read_var)) {
      return get_var(vars_map, simple_var->name_get());
    }

    Var* mother_var;
    std::string property;
    if (const SubscriptVar* subscript_var = dynamic_cast<const SubscriptVar*>(read_var)) {
      mother_var = subscript_var->var_get();
      property = evaluate(subscript_var->index_get())->to_string();
    } else if (const PropertyVar* property_var = dynamic_cast<const PropertyVar*>(read_var)) {
      mother_var = property_var->var_get();
      property = property_var->property_get();
    }
    if (ObjectValue* mother_var_object_value = dynamic_cast<ObjectValue*>(get_var(vars_map, mother_var))) {
      return mother_var_object_value->get_property(property);
    }
    return new UndefinedValue();
  }

  inline void Evaluator::set_var(std::map<std::string, Value*>* vars_map, std::string var_name, Value* value) {
    vars_map->insert_or_assign(var_name, value);
  }

  inline void Evaluator::set_var(std::map<std::string, Value*>* vars_map, Var* written_var, Value* value) {
    if (SimpleVar* simple_var = dynamic_cast<SimpleVar*>(written_var)) {
      set_var(vars_map, simple_var->name_get(), value);
      return;
    }

    Var* mother_var;
    std::string property;
    if (SubscriptVar* subscript_var = dynamic_cast<SubscriptVar*>(written_var)) {
      mother_var = subscript_var->var_get();
      property = evaluate(subscript_var->index_get())->to_string();
    } else if (PropertyVar* property_var = dynamic_cast<PropertyVar*>(written_var)) {
      mother_var = property_var->var_get();
      property = property_var->property_get();
    }
    if (ObjectValue* mother_var_object_value = dynamic_cast<ObjectValue*>(get_var(vars_map, mother_var))) {
      mother_var_object_value->set_property(property, value);
    }
  }
} // namespace runtime
