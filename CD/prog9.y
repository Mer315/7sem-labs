code:
%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int yylex();
int yyerror(char *);
%}

%union {
    int type;
}

%token NUM REAL
%type <type> E

%left '+' '-'
%left '*' '/'

%%

input:
    E
    {
        if ($1 == 1)
            printf("Type: Integer\n");
        else
            printf("Type: Real\n");

        return 0;
    }
    ;

E:
    E '+' E
    {
        if ($1 == 1 && $3 == 1)
            $$ = 1;
        else
            $$ = 2;
    }
    | E '-' E
    {
        if ($1 == 1 && $3 == 1)
            $$ = 1;
        else
            $$ = 2;
    }
    | E '*' E
    {
        if ($1 == 1 && $3 == 1)
            $$ = 1;
        else
            $$ = 2;
    }
    | E '/' E
    {
        $$ = 2;
    }
    | '(' E ')'
    {
        $$ = $2;
    }
    | NUM
    {
        $$ = 1;
    }
    | REAL
    {
        $$ = 2;
    }
    ;

%%

int yylex()
{
    int c;
    int dot = 0;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (isdigit(c)) {
        while (isdigit(c))
            c = getchar();

        if (c == '.') {
            dot = 1;
            c = getchar();

            while (isdigit(c))
                c = getchar();
        }

        if (c != EOF)
            ungetc(c, stdin);

        if (dot)
            return REAL;

        return NUM;
    }

    if (c == '+' || c == '-' || c == '*' ||
        c == '/' || c == '(' || c == ')')
        return c;

    if (c == '\n' || c == EOF)
        return 0;

    return c;
}

int yyerror(char *s)
{
    printf("Type Error\n");
    return 0;
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}

yacc -d prog9.y
gcc y.tab.c -o output
./output

Enter expression: 10+20
Type: Integer
