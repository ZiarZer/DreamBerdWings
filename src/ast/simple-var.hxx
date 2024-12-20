#pragma once

#include "simple-var.hh"

namespace ast {
  inline std::string SimpleVar::name_get() const {
    return name_;
  }
} // namespace ast
