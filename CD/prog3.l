code:
%{
#include <stdio.h>
%}

ID      [a-zA-Z_][a-zA-Z0-9_]*
NUM     [0-9]+
OP      [+\-*/=%<>]
SPEC    [][.,;:(){}]

%%

"int"|"float"|"char"|"if"|"else"|"while"|"for"|"return"|"void"|"double"  { printf("%s : Keyword\n", yytext); }

{ID}    { printf("%s : Identifier\n", yytext); }

{NUM}   { printf("%s : Constant\n", yytext); }

{OP}    { printf("%s : Operator\n", yytext); }

{SPEC}  { printf("%s : Special Symbol\n", yytext); }

[ \t\n]+    ;

.       { printf("%s : Unknown\n", yytext); }

%%

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}


rm -f lex.yy.c output
lex prog3.l
gcc lex.yy.c -o output -lfl
./output

int a = 10;
float b = 20;
a+b

int : Keyword
a : Identifier
= : Operator
10 : Constant
; : Special Symbol
float : Keyword
b : Identifier
= : Operator
20 : Constant
; : Special Symbol
a : Identifier
+ : Operator
b : Identifier
