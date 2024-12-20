#pragma once

#include "var.hh"
#include "visitor.hh"

namespace ast {
  class SimpleVar : public Var {
  public:
    SimpleVar(const Location& location, std::string name);
    SimpleVar(const SimpleVar&) = delete;
    SimpleVar& operator=(const SimpleVar&) = delete;

    std::string name_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::string name_;
  };
} // namespace ast

#include "simple-var.hxx"
