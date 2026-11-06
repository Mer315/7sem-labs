code:

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[][20] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "double"
};

int isKeyword(char str[])
{
    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char input[1000];

    printf("Enter a C statement:\n");
    fgets(input, sizeof(input), stdin);

    int i = 0;

    while (input[i] != '\0') {

        if (isspace(input[i])) {
            i++;
            continue;
        }

        /* Single-line comment */
        if (input[i] == '/' && input[i+1] == '/') {
            printf("// --> Comment\n");
            break;
        }

        /* Multi-line comment */
        if (input[i] == '/' && input[i+1] == '*') {
            printf("/* --> Comment\n");
            i += 2;

            while (input[i] != '\0' &&
                   !(input[i] == '*' && input[i+1] == '/'))
                i++;

            if (input[i] != '\0')
                i += 2;

            continue;
        }

        /* Identifier or Keyword */
        if (isalpha(input[i]) || input[i] == '_') {
            char token[50];
            int j = 0;

            while (isalnum(input[i]) || input[i] == '_') {
                if (j < 49)
                    token[j++] = input[i];
                i++;
            }

            token[j] = '\0';

            if (isKeyword(token))
                printf("%s --> Keyword\n", token);
            else
                printf("%s --> Identifier\n", token);
        }

        /* Constant */
        else if (isdigit(input[i])) {
            char num[50];
            int j = 0;

            while (isdigit(input[i]) || input[i] == '.') {
                if (j < 49)
                    num[j++] = input[i];
                i++;
            }

            num[j] = '\0';
            printf("%s --> Constant\n", num);
        }

        /* Operator */
        else if (strchr("+-*/=%<>!", input[i])) {
            printf("%c --> Operator\n", input[i]);
            i++;
        }

        /* Special Symbols */
        else if (strchr("(){}[],;#", input[i])) {
            printf("%c --> Special Symbol\n", input[i]);
            i++;
        }

        else {
            printf("%c --> Unknown\n", input[i]);
            i++;
        }
    }

    return 0;
}

gcc prog2.c -o output
./output
    
Enter a C statement:
int a = 20;
int --> Keyword
a --> Identifier
= --> Operator
20 --> Constant
; --> Special Symbol
