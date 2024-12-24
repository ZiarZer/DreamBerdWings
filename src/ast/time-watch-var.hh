#pragma once

#include "var.hh"
#include "visitor.hh"

namespace ast {
  class TimeWatchVar : public Var {
  public:
    enum class Time { past, present, future };

    TimeWatchVar(const Location& location, Var* var, Time time);
    TimeWatchVar(const TimeWatchVar&) = delete;
    TimeWatchVar& operator=(const TimeWatchVar&) = delete;

    Var* var_get() const;
    Time time_get() const;

    void accept(Visitor& v) const override;

  protected:
    Var* var_;
    Time time_;
  };

  std::string str(TimeWatchVar::Time time);
} // namespace ast

#include "time-watch-var.hxx"
