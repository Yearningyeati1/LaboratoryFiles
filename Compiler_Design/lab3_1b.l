
%{
#include <stdio.h>
#include <stdlib.h>
int a=0,b=0;
%}
%option noyywrap

%%
(0+[8-9]+($|\n)) {printf("Invalid\n");} /*Ignore invalid octals*/
([1-9]+($|U|\n)) {printf("Valid\n");} /*Unsigned,Positive integers*/
(-?([0-9]+)($|L|\n)) {printf("Valid\n");} /*Regular Integers*/
(0x)[0-9A-F]+($|\n) {printf("Valid\n");}  /*Hexadecimal*/
(-[0-9]+(U|$|\n)) {printf("Invalid\n");} /*Ignore invalid unsigned*/

[ \t\n\r]+   ;

.|\n         ; 
%%

int main() {
    printf("Enter the string \n");
    yylex(); 
    return 0;
}
