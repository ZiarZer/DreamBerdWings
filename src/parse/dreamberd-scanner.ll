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
\n          {
                driver_.location_next_line();
                return parse::DreamBerdParser::make_EOL(driver_.get_location());
            }
[\t ]       {
                // TMP: Ignore whitespaces
            }

.           {
                std::cout << driver_.get_location() << ": invalid identifier: " << yytext << std::endl; 
            }

<<EOF>>     { driver_.step_location(1); return yyterminate(); }

%%
