#pragma once

#include <vector>
#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class ObjectExp : public Exp {
  public:
    ObjectExp(const Location& location, std::vector<std::pair<std::string, Exp*>>* keyvalues);
    ObjectExp(const ObjectExp&) = delete;
    ObjectExp& operator=(const ObjectExp&) = delete;

    std::vector<std::pair<std::string, Exp*>>* keyvalues_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::vector<std::pair<std::string, Exp*>>* keyvalues_;
  };
} // namespace ast

#include "object-exp.hxx"
