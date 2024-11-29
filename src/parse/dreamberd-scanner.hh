#pragma once

#if !defined(yyFlexLexerOnce)
#  undef yyFlexLexer
#  define yyFlexLexer DreamBerd_FlexLexer // using %option prefix in .ll
#  include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL parse::DreamBerdParser::symbol_type parse::DreamBerdScanner::get_next_token()

#include "dreamberd-parser.tab.hh"

namespace parse {
  class DreamBerdDriver;

  class DreamBerdScanner : public yyFlexLexer {
  public:
    DreamBerdScanner(DreamBerdDriver& driver)
      : driver_(driver) {}
    virtual ~DreamBerdScanner() {}
    virtual DreamBerdParser::symbol_type get_next_token();

  private:
    DreamBerdDriver& driver_;
  };

} // namespace parse
