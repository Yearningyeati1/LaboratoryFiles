 %{
#include <stdio.h>
#include <stdlib.h>
%}

%{
int yylex(void);
int yyerror(char *s);
%}

/* declare tokens */
%token BOOL
%token OR AND IMP EQ LEF RIG NOT
%token EOL

%left OR
%left AND
%left IMP
%left EQ
%right NOT
%left LEF RIG
%%

calclist: /* nothing */
| calclist expr EOL { printf("VALID EXPRESSION\nRESULT:%d\n",$2); };
expr: expr OR expr {$$=$1 || $3 ;}
    | expr AND expr {$$=$1 && $3 ;}
    | expr IMP expr {$$=!$1 || $3 ;}
    | expr EQ expr {$$=!($1^$3) ;}
    | LEF expr RIG {$$=$2 ;}
    | NOT expr {$$=!$2 ;}
    | BOOL {$$=$1 ;}
    ;

%%
int main(int argc, char **argv)
{
printf("Enter proposition logic expression(use 0s & 1s,NOT VARIBLES)\n");
yyparse();
return 0;
}
int yyerror(char *s)
{
fprintf(stderr, "error: %s\n", s);
return 0;
}