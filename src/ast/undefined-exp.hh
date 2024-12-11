#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class UndefinedExp : public Exp {
  public:
    UndefinedExp(const Location& location);
    UndefinedExp(const UndefinedExp&) = delete;
    UndefinedExp& operator=(const UndefinedExp&) = delete;

    void accept(Visitor& v) const override;
  };
} // namespace ast
