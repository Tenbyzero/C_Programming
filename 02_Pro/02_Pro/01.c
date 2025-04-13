#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "Headers.h"


void choice();
void choice1();
void choice2();

int main()
{

    while (1)
    {
        printf("__________________________________________________\n");
        printf("__________________________________________________\n");
        int n;
        printf("\nEnter \n\t1 File handling\n\t2 Stack\n\t3.Queue\n\t4 Exit\n");
        printf("Enter the choice : ");
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
            choice();
            break;
        case 2:
            choice1();
            break;
        case 3:
            choice2();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Enter valid number");
            printf("\n");
        }
    }

    return 0;
}