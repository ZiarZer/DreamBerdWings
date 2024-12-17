#include "compound-statement.hh"

namespace ast {
  CompoundStatement::CompoundStatement(const Location& location, std::vector<Statement*>* statements)
    : Statement(location)
    , statements_(statements) {}

  CompoundStatement::~CompoundStatement() {
    for (auto& statement : *statements_)
      delete statement;
    delete statements_;
  }

  void CompoundStatement::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
