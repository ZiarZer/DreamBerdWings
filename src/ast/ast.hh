#pragma once

#include "location.hh"

namespace ast {
  class Ast {
  public:
    explicit Ast(const Location& location);
    Ast(const Ast&) = delete;
    Ast& operator=(const Ast&) = delete;

    virtual ~Ast() = default;

    const Location& location_get() const;
    void location_set(const Location& location);

  protected:
    Location location_;
  };
} // namespace ast

#include "ast.hxx"
