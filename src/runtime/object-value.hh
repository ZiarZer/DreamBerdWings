#pragma once

#include <map>
#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class ObjectValue : public Value {
  public:
    explicit ObjectValue(std::map<std::string, Value*> properties);
    explicit ObjectValue(std::vector<Value*> elements); // Array constructor
    ObjectValue(const ObjectValue&) = delete;
    ObjectValue& operator=(const ObjectValue&) = delete;

    std::map<std::string, Value*> properties_get() const;
    bool is_array_get() const;
    bool is_truthy(void) const override;
    Value* operator-(void) const override;
    Value* operator!(void) const override;

    void accept(Visitor& v) const override;

  protected:
    std::map<std::string, Value*> properties_;
    bool is_array_;
  };
} // namespace runtime

#include "object-value.hxx"
