// #include <stdio.h>
// #include <string.h>

// int main() {
//     int n;

//     // Ask user for the number of files to create
//     printf("How many files do you need to create? ");
//     scanf("%d", &n);

//     // Check if the number is positive
//     if (n <= 0) {
//         printf("Please enter a positive number.\n");
//         return 1;
//     }

//     // Clear the input buffer after scanf
//     while (getchar() != '\n');

//     // Loop to get filenames and create files
//     for (int i = 1; i <= n; i++) {
//         char filename[200];

//         // Prompt user for each filename
//         printf("Enter filename #%d (include extension if desired): ", i);
//         fgets(filename, sizeof(filename), stdin);

//         // Remove trailing newline from filename
//         size_t len = strlen(filename);
//         if (len > 0 && filename[len - 1] == '\n') {
//             filename[len - 1] = '\0';
//         }

//         // Create and open the file in write mode
//         FILE *file = fopen(filename, "w");
//         if (file == NULL) {
//             printf("Error opening file %s\n", filename);
//         } else {
//             // Write a message to the file
//             fprintf(file, "This is file: %s\n", filename);
//             fclose(file); // Close the file
//             printf("Created file: %s\n", filename);
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main()
{
    int n;

    // Ask how many files to create
    printf("How many files do you need to create? ");
    scanf("%d", &n);

    // Check if the number is positive
    if (n <= 0)
    {   
        printf("Please enter a positive number.\n");
        return 1;
    }

    while (getchar() != '\n')

    for (int i = 1; i <= n; i++)
    {
        char filename[200];

        printf("Enter filename #%d (include extension if desired): ", i);
        fgets(filename, sizeof(filename), stdin);

        // Remove trailing newline from filename
        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n')
        {
            filename[len - 1] = '\0';
        }

        // Create and open the file in write mode
        FILE *file = fopen(filename, "w");
        if (file == NULL)
        {
            printf("Error opening file %s\n", filename);
        }
        else
        {
            // Write message to the file
            fprintf(file, "This is file: %s\n", filename);
            fclose(file); // Close the file
            printf("Created file: %s\n", filename);
        }
    }

    return 0;
}