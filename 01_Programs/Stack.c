#include <stdio.h>
#include<stdlib.h>

#define MAX 3

int a[MAX], top = -1;

void push();
void pop();
void display();

int main()
{
    while(1)
    {
        int n;
        printf("\nEnter \n1 to push\n2 to pop\n3 to display\n4 to exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : push();break;
            case 2 : pop();break;
            case 3 : display();break;
            case 4 : exit(1);break;

        }

    }
    return 0;
}
void push()
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    int element;
    printf("Enter the element to push in the stack : ");
    scanf("%d",&element);
    top++;
    a[top] = element;

}
void pop()
{
    if(top == -1)
    {
        printf("No elements to pop\n");
        return;
    }
    printf("Popped element : %d\n",a[top]);
    top--;

}
void display()
{
    if(top == -1)
    {
        printf("No elements to display\n");
        return;
    }
    printf("\nElements in stack : \n");
    for(int i = 0;i<=top;i++)
    {
        printf("%d\t",a[i]);
    }
}


