%{
#include <stdio.h>
#include <stdlib.h>
%}
%{
int yylex(void);
int yyerror(char *s);
%}
/* declare tokens */
%token NUMBER ID
%token ADD MUL LEF RIG
%token EOL
%%

calclist: /* nothing */
| calclist E EOL { printf("VALID\n"); };
E: T 
| T ADD E 
;
T: F 
| T MUL F 
;
F: NUMBER 
| ID
| LEF E RIG
;
%%
void main(int argc, char **argv)
{
yyparse();
}
int yyerror(char *s)
{
fprintf(stderr, "error: %s\n", s);
}