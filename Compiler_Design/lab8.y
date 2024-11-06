 %{
#include<bits/stdc++.h>
using namespace std;
stack<string> q;
string postfix;
int cnt=0;
%}

%{
int yylex(void);
int yyerror(char *s);
%}

/* declare tokens */

%token VAR
%token ADD SUB MUL DIV MOD ASSIGN LEF RIG UNM
%token EOL

%left ASSIGN
%left ADD SUB
%left MUL DIV MOD
%right UNM
%left LEF RIG
%%

calclist: /* nothing */
|calclist expr EOL { cout<<"VALID EXPRESSION!! Postfix expression: \n"+postfix<<endl;
                    postfix.clear();
                    cnt=0; }

expr: expr SUB expr {
        string right=q.top();q.pop();
        string left=q.top();q.pop();

        string temp_var="t"+to_string(cnt++); //intermediate var
        cout<<temp_var<< " = "+ left + " - " +right<<endl;
        postfix+=" - ";
        q.push(temp_var);}

    | expr ADD expr {
        string right=q.top();q.pop();
        string left=q.top();q.pop();

        string temp_var="t"+to_string(cnt++); //intermediate var
        cout<<temp_var<< " = "+ left + "+" +right<<endl;
        postfix+=" + ";
        q.push(temp_var);
    }
    | expr MUL expr {
        string right=q.top();q.pop();
        string left=q.top();q.pop();

        string temp_var="t"+to_string(cnt++); //intermediate var
        cout<<temp_var<< " = "+ left + " X " +right<<endl;
        postfix+=" X ";
        q.push(temp_var);}

    | expr DIV expr {
        string right=q.top();q.pop();
        string left=q.top();q.pop();

        string temp_var="t"+to_string(cnt++); //intermediate var
        cout<<temp_var<< " = "+ left + " / " +right<<endl;
        postfix+=" / ";
        q.push(temp_var);}

    | expr MOD expr {
        string right=q.top();q.pop();
        string left=q.top();q.pop();

        string temp_var="t"+to_string(cnt++); //intermediate var
        cout<<temp_var<< " = "+ left + " \% " +right<<endl;
        postfix+=" % ";
        q.push(temp_var);}

    | LEF expr RIG {;}

    | UNM expr {
        string temp=q.top();q.pop();
        string temp_var="t"+to_string(cnt++); //intermediate var
        cout<<temp_var<< " = - "+temp<<endl;
        postfix+=" - ";
        q.push(temp_var);}

    | VAR {
        q.push(string(1, (char)yylval));//Char cast int value of the variable
        postfix+=string(1, (char)yylval)+" ";
        }
    ;

%%
int main(int argc, char **argv)
{
printf("ENTER ARITHMETIC EXPRESSION (for three address code):\n");
yyparse();
return 0;
}
int yyerror(char *s)
{
fprintf(stderr, "error: %s\n", s);
return 0;
}
