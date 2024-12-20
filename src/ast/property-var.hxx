#pragma once

#include "property-var.hh"

namespace ast {
  inline Var* PropertyVar::var_get() const {
    return var_;
  }

  inline std::string PropertyVar::property_get() const {
    return property_;
  }
} // namespace ast
