code:
%{
#include <stdio.h>
#include <string.h>

int chars = 0, spaces = 0, tabs = 0, words = 0;

char keywords[][20] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "double"
};

int isKeyword(char *s)
{
    int i;
    for(i = 0; i < 10; i++)
        if(strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}
%}

%%

[ \t\n]+ {
    int i;
    for(i = 0; yytext[i] != '\0'; i++)
    {
        if(yytext[i] == ' ')
            spaces++;
        else if(yytext[i] == '\t')
            tabs++;
    }
}

[a-zA-Z_][a-zA-Z0-9_]* {
    chars += yyleng;
    if(isKeyword(yytext))
        words++;
}

[^ \t\n]+ {
    chars += yyleng;
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter text:\n");
    yylex();

    printf("\nCharacters = %d\n", chars);
    printf("Spaces = %d\n", spaces);
    printf("Tabs = %d\n", tabs);
    printf("Reserved words = %d\n", words);

    return 0;
}

lex extra2.l
gcc lex.yy.c -o output -lfl
./output

int a = 10;
float b = 20;

Characters = 15
Spaces = 6
Tabs = 0
Reserved words = 2
