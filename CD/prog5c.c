calc.l
code:
%{
#include <stdio.h>
#include <stdlib.h>
#include "calc.tab.h"
%}

%%

[0-9]+      {
                yylval.num = atoi(yytext);
                return NUMBER;
            }

[ \t]       ;
\n          return '\n';
.           return yytext[0];

%%

int yywrap()
{
    return 1;
}

calc.y
code:
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *);
%}

%union {
    int num;
}

%token <num> NUMBER
%type <num> E

%left '+' '-'
%left '*' '/' '%'

%%

ArithmeticExpression:
    E '\n'
    {
        printf("\nResult = %d\n", $1);
        return 0;
    }
    ;

E:
      E '+' E  { $$ = $1 + $3; }
    | E '-' E  { $$ = $1 - $3; }
    | E '*' E  { $$ = $1 * $3; }
    | E '/' E  { $$ = $1 / $3; }
    | E '%' E  { $$ = $1 % $3; }
    | '(' E ')' { $$ = $2; }
    | NUMBER    { $$ = $1; }
    ;

%%

void yyerror(char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}

yacc -d -b calc calc.y
lex calc.l
gcc calc.tab.c lex.yy.c -o output -lfl 

// Enter expression: 2*9/5

// Result = 3
