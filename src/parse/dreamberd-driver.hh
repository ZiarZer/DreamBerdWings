#pragma once

#include "dreamberd-scanner.hh"

namespace parse {
  class DreamBerdDriver {
  public:
    DreamBerdDriver();

    /**
    * \returns result of the parsed operation.
    */
    int parse();

    friend class DreamBerdScanner;
    friend class DreamBerdParser;

  private:
    void step_location(unsigned int loc);
    void location_next_line();

    parse::location get_location() const;

  private:
    DreamBerdScanner scanner_;
    DreamBerdParser parser_;
    parse::location location_;
  };

} // namespace parse
