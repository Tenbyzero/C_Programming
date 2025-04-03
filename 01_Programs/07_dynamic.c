// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int i, num = 5, *ip;
//     ip = (int *)calloc(num, sizeof(int));
//     printf("address of First element : %u\n", ip);
//     // printf("Enter the %d elements\n", num);
//     // for (i = 0; i < num; i++)
//     //     scanf("%d", (ip + i));
//     ip[0] = 1;
//     ip[1] = 2;
//     ip[2] = 3;
//     ip[3] = 4;
//     ip[4] = 5;

//     printf("Array elements\n");
//     for (i = 0; i < num; i++)
//     {
//         printf("%u - %d\n", (ip + i), *(ip + i));
//     }
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ip, i, n1, n2;
    printf("Enter the size of array\n");
    scanf("%d", &n1);

    ip = (int *)calloc(n1, sizeof(int));

    printf("Enter %d elements\n", n1);
    for (i = 0; i < n1; i++)
        scanf("%d", (ip + i));

    printf("Entered %d elements are : \n", n1);
    for (i = 0; i < (n1); i++)
        printf("%u - %d\n", (ip + i), *(ip + i));

    printf("Enter the extra elements you need:");
    scanf("%d", &n2);

    ip = (int *)realloc(ip, ((n1 + n2) * sizeof(int)));

    printf("Enter extra %d elements\n", n2);
    for (i = n1; i < (n1 + n2); i++)
        scanf("%d", (ip + i));

    printf("All Array elements\n");
    for (i = 0; i < (n1 + n2); i++)
        printf("%u - %d\n", (ip + i), *(ip + i));

    free(ip);

    return 0;
}