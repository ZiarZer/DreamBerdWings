#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class CompoundStatement : public Statement {
  public:
    CompoundStatement(const Location& location, std::vector<Statement*>* statements);
    CompoundStatement(const Location& location, std::vector<Statement*>* statements, bool is_root);
    CompoundStatement(const CompoundStatement&) = delete;
    CompoundStatement& operator=(const CompoundStatement&) = delete;
    ~CompoundStatement() override;

    std::vector<Statement*>* statements_get() const;
    bool is_root_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::vector<Statement*>* statements_;
    bool is_root_;
  };
} // namespace ast

#include "compound-statement.hxx"
