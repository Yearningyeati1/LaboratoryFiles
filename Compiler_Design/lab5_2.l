/* recognize tokens for the calculator and print them out */
%{
#include "lab5_2.tab.h"
#include <stdlib.h>
char* syms[20];
int ind=0; 
%}

%%
int|float|char|double { return Types; }
(long)([ ])+(int)([ ])+|(unsigned)([ ])+(int) { return Types; }
(short)([ ])+(int)|(long)([ ])+(double) { return Types; }

[A-Za-z]([A-Za-z0-9])* {
    if(ind!=0){
for(int i=0;i<ind;i++){
    if(strcmp(yytext,syms[i])==0){
        printf("Variable already declared before!\n");
        return Error;}
}}
syms[ind]=malloc(sizeof(yytext));
strcpy(syms[ind++],yytext);
return Identifier;}

[,] { return Comma; }
(;\n) { 
        for(int i=0;i<ind;i++){
            free(syms[i]);
        }
        ind=0;
        return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%

int yywrap(){
    return 0;
}