code:

%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int yylex();
int yyerror(char *);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

input:
E
{
    printf("Result = %d\n", $1);
    return 0;
}
;

E:
E '+' E
{
    $$ = $1 + $3;
}
| E '-' E
{
    $$ = $1 - $3;
}
| E '*' E
{
    $$ = $1 * $3;
}
| E '/' E
{
    $$ = $1 / $3;
}
| '(' E ')'
{
    $$ = $2;
}
| NUMBER
{
    $$ = $1;
}
;

%%

int yylex()
{
    int c;
    int num = 0;

    while((c = getchar()) == ' ' || c == '\t');

    if(isdigit(c))
    {
        do
        {
            num = num * 10 + (c - '0');
            c = getchar();
        }
        while(isdigit(c));

        if(c != EOF)
            ungetc(c,stdin);

        yylval = num;
        return NUMBER;
    }

    if(c == '+' || c == '-' || c == '*' ||
       c == '/' || c == '(' || c == ')')
        return c;

    if(c == '\n' || c == EOF)
        return 0;

    return c;
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}

int main()
{
    printf("Enter algebraic expression: ");
    yyparse();
    return 0;
}

yacc -d prog8.y
gcc y.tab.c -o output
./output

Enter algebraic expression: 2*3/4
Result = 1
