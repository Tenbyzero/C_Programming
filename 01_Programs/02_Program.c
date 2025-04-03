/* //characters, words, Space (counting)
#include <stdio.h>

int main()

{
    FILE *f;
    f = fopen("program.txt", "w");

    if (f == NULL)
    {
        printf("File is not opened\n");
    }
    printf("File opened successfully\n");
    fprintf(f, "Hello today first class is c programming\n");
    fputs("Hello icca friends", f);

    fclose(f);

    f = fopen("program.txt", "r");
    if (f == NULL)
    {
        printf("File is not opened\n");
    }
    int i = 0;
    char c[100];
    while ((c[i] = (fgetc(f))) != EOF)
    {
        putchar(c[i]);
        i++;
    }
    rewind(f);

    int space = 0;
    int words = 0;
    int character = 0;
    int inword = 0;
    i = 0;

    while ((c[i] = (fgetc(f))) != EOF)
    {
        character++;

        if (c[i] == ' ' || c[i] == '\n' || c[i] == '\t')
        {
            space++;
            if (inword)
            {
                words++;
                inword = 0;
            }
        }
        else
        {
            inword = 1;
        }
        i++;
    }
    if (inword)
    {
        words++;
    }
    printf("\nThe no of characters in file is %d\n", character);
    printf("The no of words in file is %d\n", words);
    printf("The no of spaces in file is %d\n", space);
    fclose(f);
}
*/
/*//Program on fgetwc
#include <stdio.h>
#include <wchar.h>

int main() {
    FILE *fp;
    wint_t wc;

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        wprintf(L"Error opening file.\n");
        return 1;
    }

    while ((wc = fgetwc(fp)) != WEOF) {
        putwchar(wc);
    }

    fclose(fp);
    return 0;
}*/
