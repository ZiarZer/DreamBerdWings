#pragma once

#include "fwd.hh"

namespace runtime {
  class Visitor {
  public:
    virtual ~Visitor();

    virtual void operator()(const Value& e);
    virtual void operator()(const NullValue&) = 0;
    virtual void operator()(const UndefinedValue&) = 0;
    virtual void operator()(const StringValue&) = 0;
    virtual void operator()(const NumberValue&) = 0;
    virtual void operator()(const BoolValue&) = 0;
    virtual void operator()(const ObjectValue&) = 0;
    virtual void operator()(const FunctionValue&) = 0;

    template <typename E> void accept(E* e);
  };
} // namespace runtime

#include "visitor.hxx"
