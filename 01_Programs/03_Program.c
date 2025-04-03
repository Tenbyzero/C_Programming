//Writing students name in file
#include <stdio.h>
int main()
{
    FILE *f;
    f = fopen("sentence.txt","w");

    if(f==NULL)
    {
        printf("File is not Opened\n");
    }

    else
    {
        int n;
        char str[10][30];

        printf("Enter the range\n");
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            printf("Enter name : ");
            scanf("%s",str[i]);
        }

        for (int i = 0; i < n; i++)
        {
            fprintf(f,"Name [%d] : %s\n",i,str[i]);
        }  
    }
    fclose(f);
    printf("Names printed success fully\n");
}