#pragma once

#include "fwd.hh"
#include "visitor.hh"

namespace ast {
  class Punctuation : public Ast {
  public:
    explicit Punctuation(const Location& location, char type, int count);
    Punctuation(const Punctuation&) = delete;
    Punctuation& operator=(const Punctuation&) = delete;

    const char type_get() const;
    void type_set(const char type);

    const int count_get() const;
    void count_set(const int count);

    void accept(Visitor& v) const override;

  protected:
    char type_; // either ! or ?
    int count_;
  };
} // namespace ast

#include "punctuation.hxx"
