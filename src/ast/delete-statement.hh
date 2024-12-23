#pragma once

#include "statement.hh"
#include "var.hh"
#include "visitor.hh"

namespace ast {
  class DeleteStatement : public Statement {
  public:
    DeleteStatement(const Location& location, Var* deleted, Punctuation* punctuation);
    DeleteStatement(const DeleteStatement&) = delete;
    DeleteStatement& operator=(const DeleteStatement&) = delete;

    Var* deleted_get() const;
    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Var* deleted_;
    Punctuation* punctuation_;
  };
} // namespace ast

#include "delete-statement.hxx"
