code:
%{
#include <stdio.h>

int a=0, e=0, i=0, o=0, u=0, total=0;

void display()
{
    printf("\nNumber of vowels = %d\n\n", total);
    printf("Vowel counts:\n");
    printf("a : %d\n", a);
    printf("e : %d\n", e);
    printf("i : %d\n", i);
    printf("o : %d\n", o);
    printf("u : %d\n", u);
}
%}

%%

[aA] { a++; total++; }
[eE] { e++; total++; }
[iI] { i++; total++; }
[oO] { o++; total++; }
[uU] { u++; total++; }

\n  { display(); return 0; }

.   ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string:\n");
    yylex();
    return 0;
}

lex vowels.l
gcc lex.yy.c -o output -lfl
./output

Enter a string:
Sumedha Vithala

Number of vowels = 6

Vowel counts:
a : 3
e : 1
i : 1
o : 0
u : 1
