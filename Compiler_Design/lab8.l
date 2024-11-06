/* recognize tokens for the calculator and print them out */
%{
#include"lab8.tab.h"
#include<stdlib.h>
%}
%option noyywrap
%%
"(-)" { return UNM; }
"-" { return SUB; }
"+" { return ADD; }
"*" { return MUL; }
"=" { return ASSIGN; }
"/" { return DIV; }
"%" { return MOD; }
"(" {return LEF;}
")" {return RIG;}
[A-Z] {  yylval = (int)yytext[0]; return VAR; }
\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%
