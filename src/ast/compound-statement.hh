#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class CompoundStatement : public Statement {
  public:
    CompoundStatement(const Location& location, std::vector<Statement*>* statements);
    CompoundStatement(const CompoundStatement&) = delete;
    CompoundStatement& operator=(const CompoundStatement&) = delete;
    ~CompoundStatement() override;

    std::vector<Statement*>* statements_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::vector<Statement*>* statements_;
  };
} // namespace ast

#include "compound-statement.hxx"
