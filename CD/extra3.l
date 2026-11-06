code:

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[-]?[0-9]+ {
    int n = atoi(yytext);

    if (n > 0)
        printf("Positive Integer\n");
    else if (n < 0)
        printf("Negative Integer\n");
    else
        printf("Zero\n");
}

[ \t\n]+ ;

. {
    printf("Invalid Input\n");
}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter an integer:\n");
    yylex();
    return 0;
}

lex prog.c
gcc lex.yy.c -o output -lfl
./output

Enter an integer:
-25
Negative Integer
