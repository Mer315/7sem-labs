Expr.l
code:

%{
#include "expr.tab.h"
%}

%%
[0-9]+                  { return NUMBER; }
[a-zA-Z][a-zA-Z0-9_]*   { return ID; }
\n                      { return NL; }
.                       { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}

Expr.y
code:
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *);
%}

%token NUMBER ID NL

%left '+' '-'
%left '*' '/'

%%

stmt:
    exp NL
    {
        printf("Valid Expression\n");
        exit(0);
    }
    ;

exp:
      exp '+' exp
    | exp '-' exp
    | exp '*' exp
    | exp '/' exp
    | '(' exp ')'
    | ID
    | NUMBER
    ;

%%

int yyerror(char *msg)
{
    printf("Invalid Expression\n");
    exit(0);
}

int main()
{
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

nano Expr.y
nano Expr.l
yacc -d -b expr Expr.y
lex Expr.l
gcc expr.tab.c lex.yy.c -o output -ll
./output
  
// Enter the expression:
// a+b*c
// Valid Expression
