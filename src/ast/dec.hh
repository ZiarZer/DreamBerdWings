#pragma once

#include "ast.hh"
#include "visitor.hh"

namespace ast {
  class Dec : public Ast {
  public:
    Dec(const Location& location, std::string name);
    Dec(const Dec&) = delete;
    Dec& operator=(const Dec&) = delete;

    std::string name_get() const;

    void accept(Visitor& v) const override = 0;

  protected:
    std::string name_;
  };
} // namespace ast

#include "dec.hxx"
