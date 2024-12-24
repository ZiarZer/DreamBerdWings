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
       EOL "EOL"
       ID "id"
       NULL "null"
       UNDEFINED "undefined"
       IF "if"
       ELSE "else"
       WHEN "when"
       RETURN "return"
       DELETE "delete"
       REVERSE "reverse"
       AWAIT "await"
       PREVIOUS "previous"
       CURRENT "current"
       NEXT "next"
       ASYNC "async"
       CONST "const"
       VAR "var"
       FUNCTION "function"
       CLASS "class"
       EQ "="
       DOT "."
       COMA ","
       COLON ":"
       LPAREN "("
       RPAREN ")"
       LBRACKET "["
       RBRACKET "]"
       LBRACE "{"
       RBRACE "}"
%precedence RPAREN
%precedence ELSE
%precedence AWAIT
%token <float> NUMBER "number";
%token <std::string> STRING "string";
%token BANGS QUESTIONS
%left ADD "+" SUB "-";
%left MUL "*" DIV "/";
%left POW "^";

%type <ast::Exp*> exp
%type <std::vector<ast::Exp*>*> exps exps.1;
%type <std::pair<std::string, ast::Exp*>> keyvalue
%type <std::vector<std::pair<std::string, ast::Exp*>>*> keyvalues keyvalues.1
%type <ast::Var*> lvalue
%type <ast::VariableDec*> vardec
%type <ast::Statement*> statement;
%type <std::vector<ast::Statement*>*> statements statements.1;
%type <ast::Punctuation*> punctuation;
%type <int> BANGS QUESTIONS
%type <std::string> ID

%start program

%%

program:
    EOF { driver.terminated_ = true; return 0; }
  | EOL { driver.ast_ = nullptr; return 1; }
  | statement EOL { driver.ast_ = $1; return 1; }
  ;

statement:
    exp punctuation { $$ = driver.make_ExpStatement(@$, $1, $2); }
  | vardec punctuation { $$ = driver.make_VarDecStatement(@$, $1, $2); }
  | IF "(" exp ")" statement ELSE statement { $$ = driver.make_IfStatement(@$, $3, $5, $7); }
  | IF "(" exp ")" statement { $$ = driver.make_IfStatement(@$, $3, $5); }
  | WHEN "(" exp ")" statement { $$ = driver.make_WhenStatement(@$, $3, $5); }
  | RETURN exp punctuation { $$ = driver.make_ReturnStatement(@$, $2, $3); }
  | DELETE lvalue punctuation { $$ = driver.make_DeleteStatement(@$, $2, $3); }
  | REVERSE punctuation { $$ = driver.make_ReverseStatement(@$, $2); }
  | punctuation { $$ = driver.make_EmptyStatement(@$, $1); }
  ;

statements:
    %empty { $$ = driver.make_statements(); }
  | statements.1 { $$ = $1; }
  ;
statements.1:
    statement { $$ = driver.make_statements($1); }
  | statements.1 statement { $$ = $1; $$->push_back($2); }
  ;

punctuation:
    BANGS { $$ = driver.make_Punctuation(@$, '!', $1); }
  | QUESTIONS { $$ = driver.make_Punctuation(@$, '?', $1); }
  ;

exp:
    "null" { $$ = driver.make_NullExp(@$); }
  | "undefined" { $$ = driver.make_UndefinedExp(@$); }
  | NUMBER { $$ = driver.make_NumberExp(@$, $1); }
  | STRING { $$ = driver.make_StringExp(@$, $1); }
  | "[" exps "]" { $$ = driver.make_ArrayExp(@$, $2); }
  | "{" keyvalues "}" { $$ = driver.make_ObjectExp(@$, $2); }
  | exp ADD exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::add, $3); }
  | exp SUB exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::sub, $3); }
  | exp MUL exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::mul, $3); }
  | exp DIV exp { $$ = driver.make_BinaryOpExp(@$, $1, ast::BinaryOpExp::Oper::div, $3); }
  | AWAIT exp { $$ = driver.make_AwaitExp(@$, $2); }
  | lvalue { $$ = $1; }
  | PREVIOUS lvalue { $$ = driver.make_TimeWatchVar(@$, $2, ast::TimeWatchVar::Time::past); }
  | CURRENT lvalue { $$ = driver.make_TimeWatchVar(@$, $2, ast::TimeWatchVar::Time::present); }
  | NEXT lvalue { $$ = driver.make_TimeWatchVar(@$, $2, ast::TimeWatchVar::Time::future); }
  ;
exps:
    %empty { $$ = driver.make_exps(); }
  | exps.1 { $$ = $1; }
  ;
exps.1:
    exp { $$ = driver.make_exps($1); }
  | exps.1 COMA exp { $$ = $1; $$->push_back($3); }
  ;

keyvalue:
    ID ":" exp { $$ = std::make_pair<std::string, ast::Exp*>(std::string($1), std::move($3)); }
  | ID { $$ = std::make_pair<std::string, ast::Exp*>(std::string($1), driver.make_SimpleVar(@$, $1)); }
  ;
keyvalues:
    %empty { $$ = driver.make_keyvalues(); }
  | keyvalues.1 { $$ = $1; }
  ;
keyvalues.1:
    keyvalue { $$ = driver.make_keyvalues($1); }
  | keyvalues.1 COMA keyvalue { $$ = $1; $$->push_back($3); }
  ;

lvalue:
    ID { $$ = driver.make_SimpleVar(@$, $1); }
  | lvalue "[" exp "]" { $$ = driver.make_SubscriptVar(@$, $1, $3); }
  | lvalue "." ID { $$ = driver.make_PropertyVar(@$, $1, $3); }
  ;

vardec:
    "const" "const" ID { $$ = driver.make_VariableDec(@$, $3, nullptr, false, false); }
  | "const" "var" ID { $$ = driver.make_VariableDec(@$, $3, nullptr, false, true); }
  | "var" "const" ID { $$ = driver.make_VariableDec(@$, $3, nullptr, true, false); }
  | "var" "var" ID { $$ = driver.make_VariableDec(@$, $3, nullptr, true, true); }
  | "const" "const" ID "=" exp { $$ = driver.make_VariableDec(@$, $3, $5, false, false); }
  | "const" "var" ID "=" exp { $$ = driver.make_VariableDec(@$, $3, $5, false, true); }
  | "var" "const" ID "=" exp { $$ = driver.make_VariableDec(@$, $3, $5, true, false); }
  | "var" "var" ID "=" exp { $$ = driver.make_VariableDec(@$, $3, $5, true, true); }
  ;
%%

void parse::DreamBerdParser::error(const location &loc, const std::string &message) {
    std::cerr << driver.get_location() << ": " << message << std::endl;
}
