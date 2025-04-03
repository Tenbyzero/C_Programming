#include<stdio.h>
#include<stdlib.h>

#define MAX 3

struct Stack
{
    int a[MAX];
    int top;
    int element;
} s1;

void push()
{
    if (s1.top == MAX - 1)
    {
        printf("Stack overflow !\n");
        return;
    } 
    printf("\nEnter the element to push : ");
    scanf("%d", &s1.element);
    s1.top++;
    s1.a[s1.top] = s1.element;
}

void pop()
{
    if (s1.top == -1)
    {
        printf("No element to pop!, Stack Underflow\n");
        return;
    }
    printf("Popped element : %d\n\n", s1.a[s1.top]);
    s1.top--;
}

void display()
{
    if (s1.top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("\nStack elements\n");
    for (int i = s1.top; i >= 0; i--)
    {
        printf("%d\n", s1.a[i]);
    }
}