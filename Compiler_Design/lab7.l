/* recognize tokens for the calculator and print them out */
%{
#include"lab7.tab.h"
#include<stdlib.h>
//int yylval;
%}
%option noyywrap
%%
"\\/" { return OR; }
"/\\" { return AND; }
"->" { return IMP; }
"<->" { return EQ; }
"~" { return NOT; }
"(" {return LEF;}
")" {return RIG;}
[0-1] { yylval = atoi(yytext); return BOOL; }
\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%
