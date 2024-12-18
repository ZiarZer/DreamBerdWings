#include "compound-statement.hh"

namespace ast {
  CompoundStatement::CompoundStatement(const Location& location, std::vector<Statement*>* statements)
    : Statement(location)
    , statements_(statements)
    , is_root_(false) {}

  CompoundStatement::CompoundStatement(const Location& location, std::vector<Statement*>* statements, bool is_root)
    : Statement(location)
    , statements_(statements)
    , is_root_(is_root) {}

  CompoundStatement::~CompoundStatement() {
    for (auto& statement : *statements_)
      delete statement;
    delete statements_;
  }

  void CompoundStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
