code:
#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push()
{
    int item;

    if(top == MAXSIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    top++;
    stack[top] = item;

    printf("Element inserted: %d\n", item);
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top]);
    top--;
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Stack elements:\n");

    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

gcc prog10.c -o output
./output
  
1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter choice: 1
Enter element: 10
Element inserted: 10

1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter choice: 3
Stack elements:
10

1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter choice: 2
Deleted element: 10

1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter choice: 10
Invalid choice

1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter choice: 2
Stack Underflow

1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter choice: 4
