%{
#include <stdio.h>
#include <stdlib.h>
int a=0,b=0;
%}
%option noyywrap

%%
a {a++;}
b {b++;}

[ \t\r]+   ;

\n {if((a-b)%3==0) printf("Valid String\n"); 
else printf("Invalid\n");
a=0;b=0;}
%%

int main() {
    printf("Enter the string \n");
    yylex(); 
    return 0;
}
