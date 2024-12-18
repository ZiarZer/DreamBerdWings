#pragma once

#include "compound-statement.hh"

namespace ast {
  inline std::vector<Statement*>* CompoundStatement::statements_get() const {
    return statements_;
  }

  inline bool CompoundStatement::is_root_get() const {
    return is_root_;
  }
} // namespace ast
