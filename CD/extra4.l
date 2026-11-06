code:

%{
#include <stdio.h>
int abc = 0, xyz = 0, pqr = 0;
%}
%%
abc { abc++; }
xyz { xyz++; }
pqr { pqr++; }
[ \t\n]+ ;
. ;
%%
int yywrap(){
return 1;}
int main(){
printf("Enter text:\n");
yylex();
printf("\nPattern abc found %d %s\n", abc, (abc==1)?"time":"times");
printf("Pattern xyz found %d %s\n", xyz, (xyz==1)?"time":"times");
printf("Pattern pqr found %d %s\n", pqr, (pqr==1)?"time":"times");
return 0;}

lex extra4.l
gcc lex.yy.c -o output -lfl
./output

Enter text:
abc xyz abc pqr xyz abc

Pattern abc found 3 times
Pattern xyz found 2 times
Pattern pqr found 1 time
