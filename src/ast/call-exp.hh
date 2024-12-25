#pragma once

#include <vector>
#include "var.hh"
#include "visitor.hh"

namespace ast {
  class CallExp : public Exp {
  public:
    CallExp(const Location& location, Var* callee, std::vector<Exp*>* params);
    CallExp(const CallExp&) = delete;
    CallExp& operator=(const CallExp&) = delete;

    Var* callee_get() const;
    std::vector<Exp*>* params_get() const;

    void accept(Visitor& v) const override;

  protected:
    Var* callee_;
    std::vector<Exp*>* params_;
  };
} // namespace ast

#include "call-exp.hxx"
