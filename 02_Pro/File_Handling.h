#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void reading();
void writing();
void appending();

void binary();
void writing_in_bin();
void reading_in_bin();

void choice()
{
    while (1)
    {
        printf("__________________________________________________\n");
        printf("Enter\n\t1. Write\n\t2. Read\n\t3. Append\n\t4. Binary\n\t5 .Return Main\n\t6. Exit\n");
        int n;
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
            writing();
            break;
        case 2:
            reading();
            break;
        case 3:
            appending();
            break;
        case 4:
            binary();
            break;
        case 5:
            return;
        case 6:
            exit(1);
            break;
        default:
            printf("Enter valid number");
        }
        printf("\n");
    }
}
void writing()
{
    char str[100];
    FILE *f;
    f = fopen("Student.txt", "w");

    printf("Enter The String :\n");
    getchar();
    fgets(str, sizeof(str), stdin);
    if (fprintf(f, "%s", str) >= 0)
    {
        printf("String printed sucessfully\n");
    }
    fclose(f);
}
void reading()
{
    char str[100];
    FILE *f;
    f = fopen("Student.txt", "r");
    if (f == NULL)
    {
        perror("Error ");
    }
    else
    {
        printf("Readed string :\n");
        while (fgets(str, sizeof(str), f) != NULL)
        {
            printf("%s", str);
        }
        fclose(f);
    }
}
void appending()
{
    char str[100];
    FILE *f;

    f = fopen("Student.txt", "a");

    if (f == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        printf("Enter the string to append:\n");

        // Clear the input buffer
        while (getchar() != '\n')
            ;

        if (fgets(str, sizeof(str), stdin) != NULL)
        {
            if (fprintf(f, "%s", str) >= 0)
            {
                printf("String appended successfully\n");
            }
            else
            {
                printf("Error writing to the file\n");
            }
        }
        else
        {
            printf("Error reading input\n");
        }
        fclose(f);
    }
}
void binary()
{
    int n1;
    while(1)
    {
        printf("Enter\n\t1. Write\n\t2. Read\n\t3. GO to previus menu\n");
        printf("Enter the choice : ");
        if (scanf("%d", &n1) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (n1)
        {
        case 1:
            writing_in_bin();
            break;
    
        case 2:
            reading_in_bin();
            break;
        case 3:
            return;
        default:
            printf("Enter valid number");
            break;
        }
    }
}
void writing_in_bin()
{
    char str[100];
    FILE *f;
    f = fopen("Student_encript.bin", "wb");
    if (f == NULL)
    {
        perror("Error ");
    }
    else
    {
        printf("Enter the string to save in binary:\n");
        while (getchar() != '\n')
            ;

        fgets(str, sizeof(str), stdin);
        size_t len = strlen(str);
        // Write only the length of the string (excluding unused parts of the array)
        fwrite(str, sizeof(char), len, f);

        fclose(f);
        printf("String saved in binary format.\n");
    }
}

void reading_in_bin()
{
    char str[100] = {0};
    FILE *f;

    f = fopen("Student_encript.bin", "rb");

    if (f == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        size_t bytesRead = fread(str, sizeof(char), sizeof(str) - 1, f);

        str[sizeof(str) - 1] = '\0';

        printf("Read string from binary file:\n%s", str);

        fclose(f);
    }
}