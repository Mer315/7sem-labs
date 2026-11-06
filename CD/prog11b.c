code:

#include <stdio.h>

char input[100];
int pos = 0;
int error = 0;

void S();
void L();
void L1();

void S() {
    if (input[pos] == 'a')
        pos++;
    else if (input[pos] == '(') {
        pos++;
        L();
        if (input[pos] == ')')
            pos++;
        else
            error = 1;
    }
    else
        error = 1;
}

void L() {
    S();
    L1();
}

void L1() {
    while (input[pos] == ',') {
        pos++;
        S();
    }
}

int main() {
    printf("Enter String: ");
    scanf("%s", input);

    S();

    if (error == 0 && input[pos] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}

nano prog11b.c
gcc prog11b.c -o output
./output

Enter String: a
String Accepted
Enter String: (a,(a,a))
String Accepted
Enter String: (a,)
String Rejected
