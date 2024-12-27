#pragma once

#include "fwd.hh"

namespace runtime {
  class Value {
  public:
    explicit Value();
    Value(const Value&) = delete;
    Value& operator=(const Value&) = delete;

    virtual bool is_truthy(void) const = 0;

    virtual void accept(Visitor& v) const = 0;
  };
} // namespace runtime
