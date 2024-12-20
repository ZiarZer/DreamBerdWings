#pragma once

#include "var.hh"
#include "visitor.hh"

namespace ast {
  class PropertyVar : public Var {
  public:
    PropertyVar(const Location& location, Var* var, std::string property);
    PropertyVar(const PropertyVar&) = delete;
    PropertyVar& operator=(const PropertyVar&) = delete;

    Var* var_get() const;
    std::string property_get() const;

    void accept(Visitor& v) const override;

  protected:
    Var* var_;
    std::string property_;
  };
} // namespace ast

#include "property-var.hxx"
