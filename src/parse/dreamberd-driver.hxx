#pragma once

#include "dreamberd-driver.hh"

namespace parse {
  inline ast::NumberExp* DreamBerdDriver::make_NumberExp(const parse::location& location, int value) const {
    return new ast::NumberExp(location, value);
  }
} // namespace parse
