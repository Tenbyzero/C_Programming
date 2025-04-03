#include <stdio.h>
#include <stdlib.h>

#define maxSizeOfQueue 3

void insert(int);
void deleteq();
void display();

int q[maxSizeOfQueue];
int f = -1;
int r = -1;

int main()
{
    int choice, element;
    while (1)
    {
        printf("\nEnter\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert :");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            deleteq();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Enter the valid choice\n");
        }
    }
}
void insert(int element)
{
    if (r == (maxSizeOfQueue - 1))
    {
        printf("Queue is full, leads to overflow\n");
        return;
    }
    else
    {
        r = r + 1; // r++;
        if (f == -1)
            f++;
        q[r] = element;
    }
}
void deleteq()
{
    if (f == -1)
    {
        printf("Queue is empty, northing to delete\n");
        return;
    }
    else if(f == r)
    {
        printf("Deleted element from the queue:%d\n", q[f]);
        f = r = -1;
    }
    else
    {
        printf("Deleted element from the queue:%d\n", q[f]);
        f++;
    }
}

void display()
{
    if (f == -1)
    {
        printf("Queue is empty, northing to display\n");
        return;
    }
    else
    {
        for (int i = 0; i <= r; i++)
        {
            printf("%d\t", q[i]);
        }
    }
}