#pragma once

#include <string>
#include "value.hh"
#include "visitor.hh"

namespace runtime {
  class StringValue : public Value {
  public:
    explicit StringValue(std::string value);
    StringValue(const StringValue&) = delete;
    StringValue& operator=(const StringValue&) = delete;

    std::string value_get() const;

    void accept(Visitor& v) const override;

  protected:
    std::string value_;
  };
} // namespace runtime

#include "string-value.hxx"
