#pragma once

namespace runtime {
  class Value {
  public:
    explicit Value();
    Value(const Value&) = delete;
    Value& operator=(const Value&) = delete;
  };
} // namespace runtime
