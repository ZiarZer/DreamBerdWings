#pragma once

#include "bool-value.hh"
#include "number-value.hh"
#include "object-value.hh"

namespace runtime {
  inline std::string ObjectValue::to_string() const {
    return is_array_ ? "[Array object]" : "[Object object]";
  }

  inline std::map<std::string, Value*>* ObjectValue::properties_get() const {
    return properties_;
  }

  inline Value* ObjectValue::get_property(std::string property) {
    return properties_->at(property);
  }

  inline void ObjectValue::set_property(std::string property, Value* value) {
    properties_->insert_or_assign(property, value);
  }

  inline bool ObjectValue::is_truthy(void) const {
    return true;
  }

  inline bool ObjectValue::is_array_get() const {
    return is_array_;
  }

  inline Value* ObjectValue::operator-() const {
    return is_array_ && properties_->empty() ? new NumberValue(0) : new NumberValue();
  }

  inline Value* ObjectValue::operator!() const {
    return new BoolValue(false);
  }
} // namespace runtime
