#pragma once

#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class StringExp : public Exp {
  public:
    StringExp(const Location& location, std::string value);
    StringExp(const StringExp&) = delete;
    StringExp& operator=(const StringExp&) = delete;

    std::string value_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::string value_;
  };
} // namespace ast

#include "string-exp.hxx"
