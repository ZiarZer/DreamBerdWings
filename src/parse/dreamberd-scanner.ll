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
id              [a-zA-Z0-9]+
classkw         class(Name)?
funckw          (fu?n?c?t?i?o?n)|(un?c?t?i?o?n?)|(nc?t?i?o?n?)|(ct?i?o?n?)|(ti?o?n?)|(io?n?)|(on?)

%x SINGLE_LINE_COMMENT_ST MULTILINE_COMMENT_ST STRING_ST

%%

%{
    std::string string_accumulator = "";
%}

"//"        { BEGIN(SINGLE_LINE_COMMENT_ST); }
<SINGLE_LINE_COMMENT_ST>{
    \n        { BEGIN(INITIAL); }
    .         {}
    <<EOF>>     { }
}
"/*"        { BEGIN(MULTILINE_COMMENT_ST); }
<MULTILINE_COMMENT_ST>{
    "*/"        { BEGIN(INITIAL); }
    .           {}
    <<EOF>>     { std::cout << driver_.get_location() << "unexpected EOF" << std::endl; }
}
"\""          { BEGIN(STRING_ST); }
<STRING_ST>{
    "\\\""      { string_accumulator += "\""; }
    "\""        {  BEGIN(INITIAL); return parse::DreamBerdParser::make_STRING(string_accumulator, driver_.get_location()); }
    .           { string_accumulator += yytext; }
    <<EOF>> {std::cout << driver_.get_location() << "unexpected EOF" << std::endl;}
}

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
"^"         {
                return parse::DreamBerdParser::make_POW(driver_.get_location());
            }
"="         {
                return parse::DreamBerdParser::make_EQ(driver_.get_location());
            }
"."         {
                return parse::DreamBerdParser::make_DOT(driver_.get_location());
            }
"("         {
                return parse::DreamBerdParser::make_LPAREN(driver_.get_location());
            }
")"         {
                return parse::DreamBerdParser::make_RPAREN(driver_.get_location());
            }
"["         {
                return parse::DreamBerdParser::make_LBRACKET(driver_.get_location());
            }
"]"         {
                return parse::DreamBerdParser::make_RBRACKET(driver_.get_location());
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
"return"    {
                return parse::DreamBerdParser::make_RETURN(driver_.get_location());
            }
"delete"    {
                return parse::DreamBerdParser::make_DELETE(driver_.get_location());
            }
"reverse"   {
                return parse::DreamBerdParser::make_REVERSE(driver_.get_location());
            }
"await"     {
                return parse::DreamBerdParser::make_AWAIT(driver_.get_location());
            }
"previous"  {
                return parse::DreamBerdParser::make_PREVIOUS(driver_.get_location());
            }
"current"   {
                return parse::DreamBerdParser::make_CURRENT(driver_.get_location());
            }
"next"      {
                return parse::DreamBerdParser::make_NEXT(driver_.get_location());
            }
"async"     {
                return parse::DreamBerdParser::make_ASYNC(driver_.get_location());
            }
"const"     {
                return parse::DreamBerdParser::make_CONST(driver_.get_location());
            }
"var"       {
                return parse::DreamBerdParser::make_VAR(driver_.get_location());
            }
{funckw}    {
                return parse::DreamBerdParser::make_FUNCTION(driver_.get_location());
            }
{classkw}   {
                return parse::DreamBerdParser::make_CLASS(driver_.get_location());
            }
\n          {
                driver_.location_next_line();
                return parse::DreamBerdParser::make_EOL(driver_.get_location());
            }
[\t ]       {
                // TMP: Ignore whitespaces
            }
{id}        {
                return parse::DreamBerdParser::make_ID(yytext, driver_.get_location());
            }
.           {
                std::cout << driver_.get_location() << ": invalid identifier: " << yytext << std::endl; 
            }

<<EOF>>     { driver_.step_location(1); return yyterminate(); }
<*>.|\n     { driver_.step_location(1); return yyterminate(); }

%%
