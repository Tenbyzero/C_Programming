#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void writeData();
void readData();
void addInList();
typedef struct vegetable
{
    char name[20];
    int prize;
} veg;
int main()
{
    int n;
    while (1)
    {
        printf("\nEnter \n    1 for writing:\n    2 for reading :\n    3 for adding items in the list :\n    4 for exit from the program :\n");
        printf("\nEnter the choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            writeData();
            break;
        case 2:
            readData();
            break;
        case 3:
            addInList();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter valid choice !\n");
        }
    }
}
void writeData()
{
    FILE *fp;
    fp = fopen("project.txt", "w");
    int n;
    veg vegDetail[10];

    
    printf("\nEnter the no of vegetables you need to process : ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the vegetable [%d] : ", i + 1);
        fgets(vegDetail[i].name, sizeof(vegDetail[i].name), stdin);
        size_t len = strlen(vegDetail[i].name);
        if (len > 0 && vegDetail[i].name[len - 1] == '\n')
        {
            vegDetail[i].name[len - 1] = '\0';
        }
        printf("Enter the price of vegetable [%d] : ", i + 1);
        scanf("%d", &vegDetail[i].prize);
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "Name  : %s\t", vegDetail[i].name);
        fprintf(fp, "Prize : %d\n", vegDetail[i].prize);
    }
    fclose(fp);
}
void readData()
{
    FILE *fp;
    fp = fopen("project.txt", "r");
    if (fp == NULL)
    {
        perror("Error ");
    }
    else
    {
        int i = 1;
        char reading[200];
        printf("\n----------------------------------------\n");
        while ((fgets(reading, sizeof(reading), fp) != NULL))
        {
            printf("%d. %s", i, reading);
            i++;
        }
        printf("----------------------------------------\n");
        fclose(fp);
    }
}
void addInList()
{
    FILE *fp;
    int n;
    veg vegDetail[10];
    fp = fopen("project.txt", "a");
    printf("\nEnter the no of extra vegetables : ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the vegetable [%d] : ", i + 1);
        fgets(vegDetail[i].name, sizeof(vegDetail[i].name), stdin);
        size_t len = strlen(vegDetail[i].name);
        if (len > 0 && vegDetail[i].name[len - 1] == '\n')
        {
            vegDetail[i].name[len - 1] = '\0';
        }
        printf("Enter the price of vegetable [%d] : ", i + 1);
        scanf("%d", &vegDetail[i].prize);
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "Name  : %s\t", vegDetail[i].name);
        fprintf(fp, "Prize : %d\n", vegDetail[i].prize);
    }
    fclose(fp);
}