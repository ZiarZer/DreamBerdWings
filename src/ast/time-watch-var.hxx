#pragma once

#include "time-watch-var.hh"

namespace ast {
  inline TimeWatchVar::Time TimeWatchVar::time_get() const {
    return time_;
  }

  inline Var* TimeWatchVar::var_get() const {
    return var_;
  }
} // namespace ast
