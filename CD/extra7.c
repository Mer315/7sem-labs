parser.y

%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(char *s);
%}

%union {
    char *str;
}

%token <str> ID
%left '+' '-'
%left '*' '/'
%right '^'

%%

input:
    expr '\n' { printf("\n"); }
    ;

expr:
      ID              { printf("%s ", $1); }
    | expr '+' expr   { printf("+ "); }
    | expr '-' expr   { printf("- "); }
    | expr '*' expr   { printf("* "); }
    | expr '/' expr   { printf("/ "); }
    | expr '^' expr   { printf("^ "); }
    | '(' expr ')'
    ;

%%

void yyerror(char *s)
{
    printf("Invalid Expression\n");
}

int main()
{
    printf("Enter infix expression: ");
    yyparse();
    return 0;
}


lexer.l


%{
#include "y.tab.h"
#include <string.h>
%}

%%

[a-zA-Z0-9]+ { yylval.str = strdup(yytext); return ID; }
[ \t] ;
\n return '\n';
. return yytext[0];

%%

int yywrap()
{
    return 1;
}


// nano parser.y
// nano lexer.l
// yacc -d parser.y
// lex lexer.l
// gcc y.tab.c lex.yy.c -o output -lfl
// ./output

// a+b*c
// Enter infix expression: a b c * +
