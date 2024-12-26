#pragma once

#include <map>
#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class ObjectValue : public Value {
  public:
    explicit ObjectValue(std::map<std::string, Value*> properties);
    ObjectValue(const ObjectValue&) = delete;
    ObjectValue& operator=(const ObjectValue&) = delete;

    std::map<std::string, Value*> properties_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::map<std::string, Value*> properties_;
  };
} // namespace runtime

#include "object-value.hxx"
