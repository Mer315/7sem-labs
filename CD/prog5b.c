var.l
code:
%{
#include "var.tab.h"
%}

%%
[0-9]       { return DIGIT; }
[a-zA-Z]    { return LETTER; }
[ \t]       ;
\n          { return NL; }
.           { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}

var.y
code:
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *);
%}

%token DIGIT LETTER NL

%%

stmt:
    LETTER B NL
    {
        printf("Valid Variable\n");
        exit(0);
    }
    | LETTER NL
    {
        printf("Valid Variable\n");
        exit(0);
    }
    ;

B:
    LETTER B
    | DIGIT B
    | LETTER
    | DIGIT
    ;

%%

int yyerror(char *msg)
{
    printf("Invalid Variable\n");
    exit(0);
}

int main()
{
    printf("Enter variable:\n");
    yyparse();
    return 0;
}

yacc -d -b var var.y
lex var.l
gcc var.tab.c lex.yy.c -o output -lfl
./output

// Enter the expression:
// 1apple235
// Invalid Expression
