code:

%{
#include <stdio.h>

int lines = 0, words = 0;
%}

%%

[ \t]+      ;
\n          { lines++; }
[^ \t\n]+   { words++; }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the text (Press Ctrl+D to end input):\n");

    yylex();

    if (words > 0 && lines == 0)
        lines = 1;
    else if (words > 0)
        lines++;

    printf("\nNumber of lines = %d\n", lines);
    printf("Number of words = %d\n", words);

    return 0;
}

lex prog4.l
gcc lex.yy.c -o output -lfl
./output

Enter the text (Press Ctrl+D to end input):
I am SUmedha

Number of lines = 2
Number of words = 3
