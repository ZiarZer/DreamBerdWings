#pragma once

#include <string>
#include "fwd.hh"

namespace runtime {
  class Value {
  public:
    explicit Value();
    Value(const Value&) = delete;
    Value& operator=(const Value&) = delete;

    virtual bool is_truthy(void) const = 0;
    virtual std::string to_string() const = 0;
    virtual Value* operator-() const = 0;
    virtual Value* operator!() const = 0;

    virtual void accept(Visitor& v) const = 0;
  };
} // namespace runtime
