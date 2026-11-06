prog7.y

code:
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *);
%}

%token ID

%%

input:
    E
    {
        printf("Valid string\n");
        return 0;
    }
    ;

E:
    T Q
    ;

Q:
    '+' T Q
    |
    ;

T:
    F R
    ;

R:
    '*' F R
    |
    ;

F:
    '(' E ')'
    | ID
    ;

%%

int yylex()
{
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == 'i') {
        int d = getchar();

        if (d == 'd')
            return ID;

        if (d != EOF)
            ungetc(d, stdin);

        return c;
    }

    if (c == '+' || c == '*' || c == '(' || c == ')')
        return c;

    if (c == '\n' || c == EOF)
        return 0;

    return c;
}

int yyerror(char *s)
{
    printf("Invalid string\n");
    return 0;
}

int main()
{
    printf("Enter expression using id: ");
    yyparse();
    return 0;
}

yacc -d prog7.y
gcc y.tab.c -o output
./output

Enter expression using id: id-id+id/id
Valid string
