code:

%{
#include <stdio.h>
#include <string.h>
char words[100][50];
int lengths[100];
int count = 0;
%}
%%
[a-zA-Z]+ {
int len = strlen(yytext);
if(len > 5 && len < 10) {
strcpy(words[count], yytext);
lengths[count] = len;
count++;
}
}
[ \t\n]+ ;
. ;
%%
int yywrap() {
return 1;
}
int main(){
int i;
printf("Enter the string:\n");
yylex();
printf("\nNo. of words with length > 5 and < 10 = %d\n\n", count);
printf("Words with length > 5 and < 10:\n");
printf(" \n");
for(i = 0; i < count; i++) printf("%d. %s (length = %d)\n", i + 1, words[i], lengths[i]);
return 0;
}


lex extra5.l
gcc lex.yy.c -o output -lfl
./output

Enter the string:
hi welcome to computer design lab

No. of words with length > 5 and < 10 = 3

Words with length > 5 and < 10:

1. welcome (length = 7)
2. computer (length = 8)
3. design (length = 6)
