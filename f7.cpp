//
//File name: f7.cpp
//Project Name:
//Programmers Name:
//Date of First Revision:
//Description:
//

#include <stdio.h>
#pragma warning(disable: 4996)   //for fopen() compiler warning



int main(void)
{
    //Text file section
    FILE* textFile = fopen("myTextFile.txt", "w");  // creates a text file called myTextFile
    if (textFile != NULL)
    {
        if (fputs("This is the first line.\nThis is the second line.\n", textFile) != NULL)  // Write lines to text file
        {
            printf("Writing to text file failed.\n");

            if (fclose(textFile) != NULL)
            {
                printf("Closing text file failed.\n");
            }

            return 1;
        }

        if (fclose(textFile) != NULL)
        {
            printf("Closing text file failed.\n");
            return 1;
        }
    }
    else
    {
        printf("Opening text file failed.\n");
        return 1;
    }


    //Binary file section
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    FILE* binaryFile = fopen("myBinaryFile.data", "wb");      //"wb" formatting code for writing to binary .data file
    if (binaryFile != NULL)
    {
        size_t elements_written = fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), binaryFile);
        if (elements_written != sizeof(kBinaryData) / sizeof(unsigned short)) //must divide the total size of the array by the size of each element to determine how many elements in the kBinaryData array
        {
            printf("Writing to binary file failed.\n");

            if (fclose(binaryFile) != NULL)
            {
                printf("Closing binary file failed.\n");
            }

            return 1;
        }

        if (fclose(binaryFile) != NULL)
        {
            printf("Closing binary file failed.\n");
            return 1;
        }
    }
    else {
        printf("Opening binary file failed.");
        return 1;
    }
    





    return 0;
}


