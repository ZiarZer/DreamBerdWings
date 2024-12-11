#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class NullExp : public Exp {
  public:
    NullExp(const Location& location);
    NullExp(const NullExp&) = delete;
    NullExp& operator=(const NullExp&) = delete;

    void accept(Visitor& v) const override;
  };
} // namespace ast
