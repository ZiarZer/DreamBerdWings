%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define api.parser.class { DreamBerdParser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { parse }
%code requires
{
    namespace parse{
        class DreamBerdScanner;
        class DreamBerdDriver;
    }
}

%code top
{
    #include "dreamberd-driver.hh"
    #include "../ast/pretty-printer.hh"

    // yylex() arguments defined in parser.yy
    static parse::DreamBerdParser::symbol_type yylex(parse::DreamBerdScanner &scanner, parse::DreamBerdDriver &driver) {
        return scanner.get_next_token();
    }
}

%lex-param { parse::DreamBerdScanner &scanner }
%lex-param { parse::DreamBerdDriver &driver }
%parse-param { parse::DreamBerdScanner &scanner }
%parse-param { parse::DreamBerdDriver &driver }
%locations
%define parse.trace
%define parse.error verbose

%define api.token.prefix {TOKEN_}

%token EOF 0 "EOF"
%token EOL "EOL"
%token <uint64_t> INT "int";
%left ADD "+" SUB "-";
%left MUL "*" DIV "/";

%type <ast::Exp*> exp instruction instructions;

%start program

%%

program: instructions EOF { driver.ast_ = $1; return 0; }

instruction:
    exp EOL { std::cout << "Parsed AST: " << *$1<< std::endl << "> "; $$ = $1; }
  | EOL { std::cout << std::endl << "> "; $$ = 0; }
  ;

instructions:
    instruction { $$ = $1; }
  | instructions instruction { $1; $$ = $2; }
  ;

exp:
    INT { $$ = driver.make_NumberExp(@$, $1); }
  | exp ADD exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::add, $3); }
  | exp SUB exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::sub, $3); }
  | exp MUL exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::mul, $3); }
  | exp DIV exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::div, $3); }
  ;
%%

void parse::DreamBerdParser::error(const location &loc, const std::string &message) {
    std::cerr << driver.get_location() << ": " << message << std::endl;
}
