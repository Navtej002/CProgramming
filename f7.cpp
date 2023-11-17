//
//File name: f7.cpp
//Project Name:
//Programmers Name:
//Date of First Revision:
//Description:
//

#include <stdio.h>
#pragma warning(disable: 4996)

int main(void)
{
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

    FILE* binaryFile = fopen("myBinaryFile.txt", "wb");
    if (binaryFile != NULL)
    {
        printf("Opening binary file failed.");
        return 1;
    }





    return 0;
}


