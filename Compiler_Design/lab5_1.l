/* recognize tokens for the calculator and print them out */
%{
#include "lab5_1.tab.h"
#include <stdlib.h>
%}

%%
"+" { return ADD; }
"*" { return MUL; }
"(" { return LEF; }
")" { return RIG; }
[A-Za-z]([A-Za-z]|[0-9])* {return ID;}

[0-9]+ {return NUMBER;}
($)[ ]*\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%

int yywrap(){
    return 0;
}