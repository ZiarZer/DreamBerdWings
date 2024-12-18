%{
    #include <sstream>
	#include "dreamberd-driver.hh"

	#define yyterminate() parse::DreamBerdParser::make_EOF(driver_.get_location());

	#define YY_USER_ACTION driver_.step_location(yyleng);
%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="DreamBerdScanner"
%option prefix="DreamBerd_"

int             [0-9]+\.?
float           [0-9]*\.[0-9]+

%%

{int}|{float} {
                float number;
                std::istringstream stream(yytext);
                stream >> number;
                return parse::DreamBerdParser::make_NUMBER(number, driver_.get_location());
            }
"!"+        {
                return parse::DreamBerdParser::make_BANGS(yyleng, driver_.get_location());
            }
"¡"+        {
                // Division by 2 because the unbang char is 2 bytes long (unicode)
                return parse::DreamBerdParser::make_BANGS(-yyleng / 2, driver_.get_location());
            }
"?"+        {
                return parse::DreamBerdParser::make_QUESTIONS(yyleng, driver_.get_location());
            }
"+"         {
                return parse::DreamBerdParser::make_ADD(driver_.get_location());
            }
"-"         {
                return parse::DreamBerdParser::make_SUB(driver_.get_location());
            }
"*"         {
                return parse::DreamBerdParser::make_MUL(driver_.get_location());
            }
"/"         {
                return parse::DreamBerdParser::make_DIV(driver_.get_location());
            }
"("         {
                return parse::DreamBerdParser::make_LPAREN(driver_.get_location());
            }
")"         {
                return parse::DreamBerdParser::make_RPAREN(driver_.get_location());
            }
"null"      {
                return parse::DreamBerdParser::make_NULL(driver_.get_location());
            }
"undefined" {
                return parse::DreamBerdParser::make_UNDEFINED(driver_.get_location());
            }
"if"        {
                return parse::DreamBerdParser::make_IF(driver_.get_location());
            }
"else"      {
                return parse::DreamBerdParser::make_ELSE(driver_.get_location());
            }
"when"     {
                return parse::DreamBerdParser::make_WHEN(driver_.get_location());
            }
"break"     {
                return parse::DreamBerdParser::make_BREAK(driver_.get_location());
            }
"continue"  {
                return parse::DreamBerdParser::make_CONTINUE(driver_.get_location());
            }
"return"    {
                return parse::DreamBerdParser::make_RETURN(driver_.get_location());
            }
"await"     {
                return parse::DreamBerdParser::make_AWAIT(driver_.get_location());
            }
\n          {
                driver_.location_next_line();
                // return parse::DreamBerdParser::make_EOL(driver_.get_location());
            }
[\t ]       {
                // TMP: Ignore whitespaces
            }

.           {
                std::cout << driver_.get_location() << ": invalid identifier: " << yytext << std::endl; 
            }

<<EOF>>     { driver_.step_location(1); return yyterminate(); }

%%
