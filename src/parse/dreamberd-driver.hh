#pragma once

#include "../ast/all.hh"
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

    ast::NumberExp* make_NumberExp(const parse::location& location, int value) const;
    ast::BinaryOpExp* make_BinaryOpExp(const parse::location& location,
                                       ast::Exp* left,
                                       ast::BinaryOpExp::Oper operation,
                                       ast::Exp* right) const;

  private:
    DreamBerdScanner scanner_;
    DreamBerdParser parser_;
    parse::location location_;
    ast::Exp* ast_;
  };

} // namespace parse

#include "dreamberd-driver.hxx"
