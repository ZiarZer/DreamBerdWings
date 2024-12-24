#pragma once

#include "variable-dec.hh"
#include "visitor.hh"

namespace ast {
  class GlobalConstantDec : public VariableDec {
  public:
    GlobalConstantDec(const Location& location, std::string name, Exp* init);
    GlobalConstantDec(const GlobalConstantDec&) = delete;
    GlobalConstantDec& operator=(const GlobalConstantDec&) = delete;

    void accept(Visitor& v) const override;
  };
} // namespace ast

#include "variable-dec.hxx"
