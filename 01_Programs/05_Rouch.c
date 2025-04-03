/*
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
    // Open a file that does not exist to trigger an error
    FILE* fp = fopen("unknown.txt", "r");

    // Check if the file could not be opened
    if (fp == NULL) {
        // Print the value of errno and its associated error message
        printf("Error opening file: %s\n", strerror(errno));
        printf("Value of errno: %d\n", errno);
        }

        return 0;
        }
 */
/*//perror()
#include <stdio.h>
#include <errno.h>

int main() {
    // Attempt to open a non-existent file
    FILE* fp = fopen("unknown.txt", "r");

    if (fp == NULL) {
        // Display a custom message followed by the error description
        perror("Error opening file");
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    // Attempt to open a non-existent file
    FILE* fp = fopen("unknown.txt", "r");

    if (fp == NULL) {
        // Display the error using strerror
        printf("Error opening file: %s\n", strerror(errno));
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    // Attempt to open a non-existent file
    FILE* fp = fopen("unknown.txt", "r");

    if (fp == NULL) {
        // Using perror() to print error directly
        perror("Using perror:");
        // Using strerror() to get error message as a string and print it
        printf("Using strerror: %s\n", strerror(errno));
    }

    return 0;
}
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>
// #include <math.h>

// int main(void)
// {
//     /*---------------------------------------------------------------
//      * Part 1: Demonstrate perror() and strerror()
//      * Attempt to open a non-existent file to generate an error.
//      *---------------------------------------------------------------*/
//     FILE *fp = fopen("nonexistent.txt", "r");
//     if (fp == NULL)
//     {
//         // Using perror() to print an error message to stderr.
//         perror("perror: Error opening file 'nonexistent.txt'");

//         // Using strerror() to print the error message.
//         printf("strerror: Error opening file 'nonexistent.txt': %s\n", strerror(errno));
//     }
//     else
//     {
//         // If the file unexpectedly opens, close it.
//         fclose(fp);
//     }

//     /*---------------------------------------------------------------
//      * Part 2: Demonstrate ferror(), feof(), and clearerr()
//      * Create a temporary file, write to it, and then read it.
//      *---------------------------------------------------------------*/
//     fp = fopen("temp.txt", "w+");
//     if (fp == NULL)
//     {
//         perror("Error creating 'temp.txt'");
//         exit(1); // Non-zero exit status indicates an error.
//     }

//     // Write some sample data into the file.
//     fprintf(fp, "Hello, world!\nThis is a test file.\n");

//     // Rewind the file pointer to the beginning for reading.
//     rewind(fp);

//     printf("\nReading from 'temp.txt':\n");
//     int ch;
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         putchar(ch);
//     }

//     // Check if the end-of-file indicator is set.
//     if (feof(fp))
//     {
//         printf("\nfeof: End of file reached.\n");
//     }

//     // Check if any reading error occurred.
//     if (ferror(fp))
//     {
//         perror("ferror: Error occurred during reading");
//     }

//     // Clear both the EOF and error indicators for the stream.
//     clearerr(fp);
//     printf("clearerr: EOF and error flags cleared.\n");

//     // Close the temporary file.
//     fclose(fp);

//     /*---------------------------------------------------------------
//      * Part 3: Demonstrate Divide by Zero Error
//      * Floating-point division by zero does not crash the program,
//      * but it yields special values (like infinity).
//      *---------------------------------------------------------------*/
//     double num = 10.0, den = 0.0;
//     double result = num / den; // According to IEEE 754, result becomes infinity.

//     if (isinf(result))
//     {
//         printf("\nFloating-point division: %.2f / %.2f = Infinity\n", num, den);
//     }
//     else
//     {
//         printf("\nFloating-point division result: %f\n", result);
//     }

//     // Uncomment the following block to see integer division by zero error.
//     // Warning: This will likely cause the program to crash (SIGFPE).
//     /*
//     int a = 10, b = 0;
//     int c = a / b;  // Integer division by zero (undefined behavior)
//     printf("Integer division: %d / %d = %d\n", a, b, c);
//     */

//     /*---------------------------------------------------------------
//      * Part 4: Exit Status
//      * Returning 0 indicates that the program executed successfully.
//      * A non-zero value (like exit(1)) above indicates an error.
//      *---------------------------------------------------------------*/
//     return 0;
// }


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

int main(void)
{
    FILE *fp = fopen("nonexistent.txt", "r");
    if (fp == NULL)
    {
        perror("perror: Error opening file 'nonexistent.txt'");
        printf("strerror: Error opening file 'nonexistent.txt': %s\n", strerror(errno));
    }
    else
    {
        fclose(fp);
    }

    fp = fopen("temp.txt", "w+");
    if (fp == NULL)
    {
        perror("Error creating 'temp.txt'");
        exit(1);
    }

    fprintf(fp, "Hello, world!\nThis is a test file.\n");
    rewind(fp);
    printf("\nReading from 'temp.txt':\n");
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    if (feof(fp))
    {
        printf("\nfeof: End of file reached.\n");
    }
    if (ferror(fp))
    {
        perror("ferror: Error occurred during reading");
    }
    clearerr(fp);
    printf("clearerr: EOF and error flags cleared.\n");
    fclose(fp);

    double num = 10.0, den = 0.0;
    double result = num / den;
    if (isinf(result))
    {
        printf("\nFloating-point division: %.2f / %.2f = Infinity\n", num, den);
    }
    else
    {
        printf("\nFloating-point division result: %f\n", result);
    }

    return 0;
}
    */
/*
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{

    FILE *f;
    f = fopen("unknown.txt", "r");
    if (f == NULL)
    {
        perror("Error ");
        printf("Value of errno: %d\n", errno);
        printf("Error from strerror : %s\n", strerror(errno));
    }
    else
    {
        printf("File opened sucessfully\n");
    }

    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    // Open the file in read mode
    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL)
    {
        // Print an error message
        // if file opening fails
        perror("Error opening file");
        // Return with non-zero exit status to
        // indicate an error
        return 1;
    }
    int c;
    // Process the character
    // Add your code here to perform operations on each
    // character read from the file
    while ((c = fgetc(file)) != EOF)
    {
    }
    if (ferror(file))
    {
        // Print an error message if an error occurred
        // during file reading

        printf("An error occurred while reading the file.\n");
    }
    else
    {
        // Print success message if file reading completed
        // without errors
        printf("File read successfully.\n");
    }
    // Close the file
    fclose(file);
    // Return with zero exit status to indicate successful
    // execution
    return 0;
}
*/

#include <stdio.h>

    int main()
{
    // Open the file in read mode
    FILE *fptr = fopen("priya.txt", "r");
    if (fptr == NULL)
    {
        printf("No such file");
        return 0;
    }

    // Read the file character by character until the end of file
    while (!feof(fptr))
    {
        char c = fgetc(fptr);
        if (feof(fptr))
            break;
        putchar(c);
    }

    // Close the file
    fclose(fptr);

    return 0;
}