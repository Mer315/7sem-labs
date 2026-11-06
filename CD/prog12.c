code:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char prod[MAX][20];
char first[MAX][20];
char nt[MAX];
int n, count = 0;

int indexNT(char c) {
    for(int i = 0; i < count; i++)
        if(nt[i] == c)
            return i;
    return -1;
}

void add(char set[], char c) {
    if(strchr(set, c) == NULL) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

void findFirst() {
    int change = 1;

    while(change) {
        change = 0;

        for(int i = 0; i < n; i++) {
            char *rhs = strchr(prod[i], '>');
            if(rhs == NULL)
                rhs = strchr(prod[i], '=');
            rhs++;

            int idx = indexNT(prod[i][0]);

            if(isupper(rhs[0])) {
                int id = indexNT(rhs[0]);

                for(int j = 0; first[id][j]; j++) {
                    if(!strchr(first[idx], first[id][j])) {
                        add(first[idx], first[id][j]);
                        change = 1;
                    }
                }
            }
            else {
                char c = rhs[0];
                add(first[idx], c);
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=E+T):\n");

    for(int i = 0; i < n; i++) {
        scanf("%s", prod[i]);

        if(indexNT(prod[i][0]) == -1)
            nt[count++] = prod[i][0];
    }

    for(int i = 0; i < count; i++)
        first[i][0] = '\0';

    findFirst();

    printf("\nFIRST SETS\n");

    for(int i = 0; i < count; i++) {
        printf("FIRST(%c) = { ", nt[i]);

        for(int j = 0; first[i][j]; j++) {
            printf("%c", first[i][j]);

            if(first[i][j + 1])
                printf(", ");
        }

        printf(" }\n");
    }

    return 0;
}

nano prog12.c
gcc prog12.c -o output
./output

Enter number of productions: 6
Enter productions (Example: E=E+T):
E=E+T
E=T
T=T*F
T=F
F=(E)
F=id

FIRST SETS
FIRST(E) = { (, i }
FIRST(T) = { (, i }
FIRST(F) = { (, i }

