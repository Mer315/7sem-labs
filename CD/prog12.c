#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROD 50
#define MAX_LEN  100
#define MAX_NT   26

char prod[MAX_PROD][MAX_LEN];
int n;

int firstSet[MAX_NT][128];
int nullable[MAX_NT];

int addFirst(int nt, int terminal)
{
    if (!firstSet[nt][terminal])
    {
        firstSet[nt][terminal] = 1;
        return 1;
    }
    return 0;
}

int firstOfSequence(const char *s, int *result)
{
    int changed = 0;
    int allNullable = 1;
    int i;

    if (s[0] == '\0' || strcmp(s, "#") == 0)
        return 0;

    for (i = 0; s[i] != '\0'; )
    {
        char c = s[i];

        if (c == 'i' && s[i + 1] == 'd')
        {
            result[256] = 1;
            allNullable = 0;
            break;
        }

        if (c == '#')
        {
            i++;
            continue;
        }

        if (!isupper((unsigned char)c))
        {
            result[(unsigned char)c] = 1;
            allNullable = 0;
            break;
        }

        {
            int nt = c - 'A';
            int t;

            for (t = 0; t < 128; t++)
            {
                if (firstSet[nt][t] && !result[t])
                {
                    result[t] = 1;
                    changed = 1;
                }
            }

            if (!nullable[nt])
            {
                allNullable = 0;
                break;
            }
        }

        i++;
    }

    if (allNullable)
        result[257] = 1;

    return changed;
}

int main(void)
{
    int i, j, changed;

    printf("Enter number of productions: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_PROD)
    {
        printf("Invalid number of productions.\n");
        return 1;
    }

    printf("Enter productions (use # for epsilon, e.g. A=BC):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%99s", prod[i]);

        if (strchr(prod[i], '=') == NULL ||
            !isupper((unsigned char)prod[i][0]))
        {
            printf("Invalid production: %s\n", prod[i]);
            return 1;
        }
    }

    do
    {
        changed = 0;

        for (i = 0; i < n; i++)
        {
            char *rhs = strchr(prod[i], '=') + 1;
            int nt = prod[i][0] - 'A';
            int result[258] = {0};

            firstOfSequence(rhs, result);

            for (j = 0; j < 128; j++)
            {
                if (result[j] && !firstSet[nt][j])
                {
                    firstSet[nt][j] = 1;
                    changed = 1;
                }
            }

            if (result[256] && !firstSet[nt]['i'])
            {
                /*
                 * Store "id" using the marker 'i'.
                 * Printing handles this marker specially.
                 */
                firstSet[nt]['i'] = 1;
                changed = 1;
            }

            if (result[257] && !nullable[nt])
            {
                nullable[nt] = 1;
                changed = 1;
            }
        }

    } while (changed);

    printf("\nFIRST sets:\n");

    for (i = 0; i < n; i++)
    {
        int nt = prod[i][0] - 'A';
        int alreadyPrinted = 0;

        for (j = 0; j < i; j++)
        {
            if (prod[j][0] == prod[i][0])
                alreadyPrinted = 1;
        }

        if (alreadyPrinted)
            continue;

        printf("FIRST(%c) = { ", prod[i][0]);

        if (firstSet[nt]['('])
            printf("( ");

        if (firstSet[nt]['+'])
            printf("+ ");

        if (firstSet[nt]['*'])
            printf("* ");

        if (firstSet[nt][')'])
            printf(") ");

        if (firstSet[nt]['i'])
            printf("id ");

        for (j = 0; j < 128; j++)
        {
            if (firstSet[nt][j] &&
                j != '(' && j != '+' && j != '*' &&
                j != ')' && j != 'i')
            {
                printf("%c ", j);
            }
        }

        if (nullable[nt])
            printf("# ");

        printf("}\n");
    }

    return 0;
}
