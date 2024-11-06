%{
#include <stdio.h>
#include <stdlib.h>
%}
%option noyywrap

%%

([HCNO]|(SI|S|CL|SN))(([1-9][0-9]*)?)(,([HCNO]|(SI|S|CL|SN))(([1-9][0-9]*)?))*($|\n) {printf("Valid\n");}

[^,\n]+[\n]  ;


%%

int main() {
    printf("Enter the string \n");
    yylex(); 
    return 0;
}
