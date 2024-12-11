#pragma once

#include "fwd.hh"

namespace ast {
  class Visitor {
  public:
    virtual ~Visitor();

    virtual void operator()(const Ast& e);
    virtual void operator()(const NullExp&) = 0;
    virtual void operator()(const NumberExp&) = 0;
    virtual void operator()(const BinaryOpExp&) = 0;
    virtual void operator()(const UndefinedExp&) = 0;
    template <typename E> void accept(E* e);
    template <class E> void operator()(E* e);
  };
} // namespace ast

#include "visitor.hxx"
