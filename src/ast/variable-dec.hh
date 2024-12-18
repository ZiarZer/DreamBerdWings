#pragma once

#include "dec.hh"
#include "visitor.hh"

namespace ast {
  class VariableDec : public Dec {
  public:
    VariableDec(const Location& location, std::string name, Exp* init, bool reassignable, bool editable);
    VariableDec(const VariableDec&) = delete;
    VariableDec& operator=(const VariableDec&) = delete;

    Exp* init_get() const;
    bool editable_get() const;
    bool reassignable_get() const;

    void accept(Visitor& v) const override;

  protected:
    Exp* init_;
    bool editable_;
    bool reassignable_;
  };
} // namespace ast

#include "variable-dec.hxx"
