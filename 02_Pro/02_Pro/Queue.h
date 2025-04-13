#include <stdio.h>
#include <stdlib.h>

// Main Declarations
void choice2();

// ------ Linear Queue ------
#define maxSizeOfQueue 3

void linear_queue();

void insert(int);
void deleteq();
void display1();

int q[maxSizeOfQueue];
int f = -1;
int r = -1;

// ------ Circular Queue ------
void circular_queue();

int i, select_choice, element, queue_Size, Cqueue[10];
int cRare = -1, cFront = -1;

void cqInsert();
void cqDelete();
void cqDisplay();




// ------ Main Function ------
void choice2()
{
    int choice;
    while (1)
    {
        printf("__________________________________________________\n");
        printf("\nEnter\n\t1.Linear Queue\n\t2.Circular Queue\n\t3.Return\n\t4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linear_queue();
            break;
        case 2:
            circular_queue();
            break;
        case 3:
            return;
            break;
        case 4:
            exit(0);
        default:
            printf("Enter the valid choice\n");
        }
    }
}

// ------ Linear Queue ------
void linear_queue()
{
    int choice, element;
    while (1)
    {
        printf("\n----------Linear Queue----------\n");
        printf("\nEnter\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Return\n\t5.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert:");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            deleteq();
            break;
        case 3:
            display1();
            break;
        case 4:
            return;
            break;
        case 5:
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
    else if (f == r)
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

void display1()
{
    if (f == -1)
    {
        printf("Queue is empty, northing to display\n");
        return;
    }
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d\t", q[i]);
        }
    }
}


// ------ Circular Queue ------
void circular_queue()
{
    printf("\n----------Circular Queue----------\n");
    printf("Enter the size of the circular Queue:");
    scanf("%d", &queue_Size);
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Return\n\t5.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &select_choice);
        switch (select_choice)
        {
        case 1:
            cqInsert();
            break;
        case 2:
            cqDelete();
            break;
        case 3:
            cqDisplay();
            break;
        case 4:
            return;
            break;
        case 5:
            exit(0);
        default:
            printf("Enter the valid choice\n");
        }
    }
}
void cqInsert()
{
    if (cFront == (cRare + 1) % queue_Size)
    {
        printf("Queue is full, leads to overflow!\n");
        return;
    }
    printf("Enter the element:");
    scanf("%d", &element);

    cRare = (cRare + 1) % queue_Size;

    Cqueue[cRare] = element;

    if (cFront == -1)
        cFront++;
}
void cqDelete()
{
    if (cFront == -1)
    {
        printf("Circular Queue is empty, leads to underflow!\n");
        return;
    }
    printf("Deleted element is:%d\n", Cqueue[cFront]);
    if (cFront == cRare)
        cFront = cRare = -1;
    else
        cFront = (cFront + 1) % queue_Size;
}
void cqDisplay()
{
    if (cFront == -1 && cRare == -1)
    {
        printf("Queue is empty, nothing to Display\n");
        return;
    }
    printf("\nQueue elements are:\t");
    /*
    for(i=cFront;i<=cRare;i++)
        {
            printf("%d\t",Cqueue [[i]);
        }
    */
    i = cFront;
    while (i != cRare)
    {
        printf("%d\t", Cqueue[i]);
        i = (i + 1) % queue_Size;
    }
    printf("%d\n", Cqueue[i]);
}
