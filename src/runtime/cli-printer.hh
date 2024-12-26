#pragma once

#include <ostream>
#include "visitor.hh"

namespace runtime {
  class CLIPrinter : virtual public Visitor {
  public:
    using Visitor::operator();

    CLIPrinter(std::ostream& stream);

    void operator()(const NullValue&) override;
    void operator()(const UndefinedValue&) override;
    void operator()(const NumberValue& e) override;
    void operator()(const StringValue& e) override;
    void operator()(const ObjectValue& e) override;

  protected:
    std::ostream& stream_;
  };

  std::ostream& operator<<(std::ostream& ostr, const Value& val);
} // namespace runtime
