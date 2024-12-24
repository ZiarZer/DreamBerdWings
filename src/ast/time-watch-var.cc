#include "time-watch-var.hh"

namespace ast {
  TimeWatchVar::TimeWatchVar(const Location& location, Var* var, TimeWatchVar::Time time)
    : Var(location)
    , var_(var)
    , time_(time) {}

  std::string str(TimeWatchVar::Time time) {
    switch (time) {
    case TimeWatchVar::Time::past:
      return "previous";
    case TimeWatchVar::Time::present:
      return "current";
    case TimeWatchVar::Time::future:
      return "next";
    default:
      return "";
    }
  }

  void TimeWatchVar::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast
