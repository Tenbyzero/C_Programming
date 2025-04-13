#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

#define MAX 3

int a[MAX], top = -1;

void choice1()
{
    while (1)
    {
        printf("__________________________________________________\n");
        int n;
        printf("\nEnter \n\t1. push\n\t2. pop\n\t3. display\n\t4. Return\n\t5. Exit\n");
        if (scanf("%d", &n) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (n)
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
            return;
            break;
        case 5:
            exit(1);
            break;

        default:
            printf("Enter valid number");
            printf("\n");
        }
    }
}

void push()
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {

        int element;
        printf("Enter the element to push in the stack : ");
        scanf("%d", &element);
        top++;
        a[top] = element;
    }
    }
void pop()
{
    if (top == -1)
    {
        printf("No elements to pop\n");
        return;
    }
    printf("Popped element : %d\n", a[top]);
    top--;
}
void display()
{
    if (top == -1)
    {
        printf("No elements to display\n");
        return;
    }
    printf("\nElements in stack : \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
