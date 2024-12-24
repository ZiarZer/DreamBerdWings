#pragma once

#include <vector>
#include "exp.hh"
#include "visitor.hh"

namespace ast {
  class ArrayExp : public Exp {
  public:
    ArrayExp(const Location& location, std::vector<Exp*>* elems);
    ArrayExp(const ArrayExp&) = delete;
    ArrayExp& operator=(const ArrayExp&) = delete;

    std::vector<Exp*>* elems_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::vector<Exp*>* elems_;
  };
} // namespace ast

#include "array-exp.hxx"
