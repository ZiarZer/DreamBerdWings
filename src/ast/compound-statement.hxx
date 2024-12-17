#pragma once

#include "compound-statement.hh"

namespace ast {
  inline std::vector<Statement*>* CompoundStatement::statements_get() const {
    return statements_;
  }
} // namespace ast
