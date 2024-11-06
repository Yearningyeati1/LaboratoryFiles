%{
#include <stdio.h>
#include <stdlib.h>
%}
%{
int yylex(void);
int yyerror(char *s);
extern int yylex();
extern int yyleng;
extern char *yytext;

%}
/* declare tokens */
%token Types Identifier Error
%token EOL Comma
%%

Start: /* nothing */
| Start DECLARATION EOL { printf("VALID\n"); };

DECLARATION: TYPE VARS ;

VARS: Identifier | VARS Comma Identifier ;

TYPE: Types ;

%%
void main(int argc, char **argv)
{
yyparse();
}
int yyerror(char *s)
{
fprintf(stderr, "Error at position: %d \n", yyleng+1);
}