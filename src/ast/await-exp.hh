#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class AwaitExp : public Exp {
  public:
    AwaitExp(const Location& location, Exp* awaited);
    AwaitExp(const AwaitExp&) = delete;
    AwaitExp& operator=(const AwaitExp&) = delete;

    Exp* awaited_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* awaited_;
  };
} // namespace ast

#include "await-exp.hxx"
