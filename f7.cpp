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


    FILE* textFile = fopen("myTextFile.txt", "w");  //creates a text file called myTextFile
    if (textFile != NULL) 
    {

        if (fputs("This is line 1.\nThis is line 2.\n", textFile) != NULL)  // Write lines to text file
        {
            printf("Writing to text file failed.\n");
            if (fclose(textFile) != 0);
            {
                printf("Closing text file failed.");
            }

            return 1;
        }
        else {
            printf("Opening text file failed.\n");
            return 1;
        }

    }
    
        



	return 0;
}