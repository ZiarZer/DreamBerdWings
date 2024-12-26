#pragma once

#include "value.hh"
#include "visitor.hh"

namespace runtime {
  inline Visitor::~Visitor() {}

  inline void Visitor::operator()(const Value& e) {
    e.accept(*this);
  }
} // namespace runtime
