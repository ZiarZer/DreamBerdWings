#pragma once

#include "statement.hh"
#include "visitor.hh"

namespace ast {
  class FunDecStatement : public Statement {
  public:
    FunDecStatement(const Location& location, FunctionDec* fundec);
    FunDecStatement(const FunDecStatement&) = delete;
    FunDecStatement& operator=(const FunDecStatement&) = delete;

    FunctionDec* fundec_get() const;

    void accept(Visitor& v) const override;

  protected:
    FunctionDec* fundec_;
  };
} // namespace ast

#include "fun-dec-statement.hxx"
