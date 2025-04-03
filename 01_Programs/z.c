//srack using array
#include <stdio.h>
#include <stdlib.h>

#include "z1.h"

void push();
void pop();
void display();

int main()
{
    int n;
    s1.top = -1;
    while (1)
    {
        printf("\n1.Push\n2.pop\n3.display\n4.exit\n");
        printf("Enter the choice : ");
        scanf("%d", &n);
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
            exit(1);
            break;

        default:
            printf("Enter valid choice !\n");
            break;
        }
    }
    return 0;
}
