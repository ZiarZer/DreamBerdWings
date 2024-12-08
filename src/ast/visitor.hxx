#pragma once

#include "ast.hh"
#include "visitor.hh"

namespace ast {
  inline Visitor::~Visitor() {}

  template <typename E> void Visitor::operator()(E* e) {
    e->accept(*this);
  }

  inline void Visitor::operator()(const Ast& e) {
    e.accept(*this);
  }
} // namespace ast