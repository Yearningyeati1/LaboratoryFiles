
%{
#include <stdio.h>
#include <stdlib.h>
int a=0,b=0;
%}
%option noyywrap

%%

([0-9]+[.][0-9]+(f?))($|\n) {printf("Valid\n");}
([0-9]+[.][0-9]+)(E-?[0-9]+)($|\n) {printf("Valid\n");}

[ \t\n\r]+   ;

.|\n         ; 
%%

int main() {
    printf("Enter the string \n");
    yylex(); 
    return 0;
}
