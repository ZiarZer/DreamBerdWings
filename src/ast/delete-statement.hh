#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class DeleteStatement : public Statement {
  public:
    DeleteStatement(const Location& location, Punctuation* punctuation);
    DeleteStatement(const DeleteStatement&) = delete;
    DeleteStatement& operator=(const DeleteStatement&) = delete;

    Punctuation* punctuation_get() const;

    void accept(Visitor& v) const override;

  protected:
    Punctuation* punctuation_;
  };
} // namespace ast

#include "delete-statement.hxx"
