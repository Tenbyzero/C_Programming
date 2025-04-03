#include <stdio.h>

int main()

{
    FILE *f;
    f = fopen("sentence.txt", "w");

    if (f == NULL)
    {
        printf("File is not opened\n");
    }
    else
    {
        printf("\nFile opened successfully\n");
        // fprintf(f,"Hello today first class is c programming\n");
        fputs("Hello everyone i am keshav", f);

        fclose(f);

        f = fopen("sentence.txt", "r");
        if (f == NULL)
        {
            printf("File is not opened\n");
        }

        char c;
        while ((c = (fgetc(f))) != EOF)
        {
            putchar(c);
        }
        rewind(f);

        int space = 0;
        int words = 0;
        int character = 0;
        while ((c = (fgetc(f))) != EOF)
        {
            character++;

            if (c == ' ')
            {
                space++;
                words++;
            }
        }
        printf("\nThe no of characters in file is %d\n", character);
        printf("The no of words in file is %d\n", words + 1);
        printf("The no of spaces in file is %d\n", space);
    }

    fclose(f);
}
