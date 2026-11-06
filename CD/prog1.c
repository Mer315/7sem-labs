code:
#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[20];
    int value;
};

int main()
{
    struct Symbol table[100];
    int n, i;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of symbols\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Symbol Name: ");
        scanf("%19s", table[i].name);

        printf("Enter Data Type: ");
        scanf("%19s", table[i].type);

        printf("Enter Value: ");
        scanf("%d", &table[i].value);
    }

    printf("\nSYMBOL TABLE\n");
    printf("-------------------------\n");
    printf("Name\tType\tValue\n");
    printf("-------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%s\t%s\t%d\n",
               table[i].name,
               table[i].type,
               table[i].value);
    }

    return 0;
}

Enter number of symbols: 2

Enter Symbol Name: a
Enter Data Type: int
Enter Value: 20

Enter Symbol Name: b
Enter Data Type: str
Enter Value: abc

SYMBOL TABLE
-------------------------
Name    Type    Value
-------------------------
a       int     20
b       str     0


// to run it
nano prog1.c
gcc prog1.c -o output
./output
