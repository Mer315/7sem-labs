code:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char prod[MAX][20];
char nt[MAX];
char follow[MAX][20];
int n, count = 0;

int indexNT(char c) {
    for(int i = 0; i < count; i++)
        if(nt[i] == c)
            return i;
    return -1;
}

void add(char *set, char c) {
    if(!strchr(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

void findFollow() {
    add(follow[0], '$');

    int change = 1;

    while(change) {
        change = 0;

        for(int i = 0; i < n; i++) {
            char *rhs = strchr(prod[i], '>') + 1;
            int A = indexNT(prod[i][0]);

            for(int j = 0; rhs[j]; j++) {
                if(isupper(rhs[j])) {
                    int B = indexNT(rhs[j]);

                    if(rhs[j+1] && !isupper(rhs[j+1])) {
                        if(!strchr(follow[B], rhs[j+1])) {
                            add(follow[B], rhs[j+1]);
                            change = 1;
                        }
                    }
                    else if(rhs[j+1] == '\0') {
                        for(int k = 0; follow[A][k]; k++) {
                            if(!strchr(follow[B], follow[A][k])) {
                                add(follow[B], follow[A][k]);
                                change = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions:\n");

    for(int i = 0; i < n; i++) {
        scanf("%s", prod[i]);

        if(indexNT(prod[i][0]) == -1)
            nt[count++] = prod[i][0];

        follow[i][0] = '\0';
    }

    findFollow();

    printf("\nFOLLOW SETS\n");

    for(int i = 0; i < count; i++) {
        printf("FOLLOW(%c) = { ", nt[i]);

        for(int j = 0; follow[i][j]; j++) {
            printf("%c", follow[i][j]);
            if(follow[i][j+1])
                printf(", ");
        }

        printf(" }\n");
    }

    return 0;
}


gcc extra6.c -o output
./output

Enter number of productions: 6
Enter productions:
E->E+T
E->T
T->T*F
T->F
F->(E)
F->id

FOLLOW SETS
FOLLOW(E) = { $, +, ) }
FOLLOW(T) = { $, +, *, ) }
FOLLOW(F) = { $, +, *, ) }
