/*
* Filename:
* Project Name: Navtej Saini
* Programmer's Name:
* Date of First Revision:
* Description:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)  //To avoid compiler warning from  fopen() 

#define MAX_STRING_LENGTH 21   //Constant for string length
#define MAX_FULLPATH_LENGTH 100  //Constant for string length


void displayError(const char* error);  //prototype for display error function. 


 struct MyData{
	int howMany;
	char theText[MAX_STRING_LENGTH] = { 0 };
	char directoryPath[MAX_STRING_LENGTH] = { 0 };
	char filename[MAX_STRING_LENGTH] = { 0 };
 };



int main(int argc, char* argv[])
{
	if (argc != 5)       //Checks if correct number of command-line arguments were given.
	{
		displayError("Incorrect number of arguments.");
		return 1;
	}


	struct MyData args;
	args.howMany = atoi(argv[1]);


	if (args.howMany <= 0)      //Checks if argv[1] is a postive integer.
	{
		displayError("First argument must be a postive integer.");
		return 1;
	}
	

	strncpy(args.theText, argv[2], MAX_STRING_LENGTH - 1);
	args.theText[MAX_STRING_LENGTH - 1] = '\0';   //Null-terminates at the end of string.

	strncpy(args.directoryPath, argv[3], MAX_STRING_LENGTH - 1);
	args.directoryPath[MAX_STRING_LENGTH - 1] = '\0';   //Null-terminates at the end of string.

	strncpy(args.filename, argv[4], MAX_STRING_LENGTH - 1);
	args.filename[MAX_STRING_LENGTH - 1] = '\0';   //Null-terminates at the end of string.


	char fullPath[MAX_FULLPATH_LENGTH] = { 0 };
	strcpy(fullPath, args.directoryPath);      
	strcat(fullPath, "\\");
	strcat(fullPath, args.filename);


	#pragma warning(disable:4996)
	FILE* textFile = fopen(fullPath, "w");

	if( textFile == NULL )
	{
		displayError("Can't Open File.");   //error checking
		return 1;
	}

	for (int i = 0; i < args.howMany; i++)  // Writes 'theText' field's contents in each line of file until 'howMany' is reached. 
	{
		if (fprintf(textFile, "%s\n", args.theText) < 0) 
		{
			displayError("Error writing to the file.");  //error checking
			
			if (fclose(textFile) == NULL)   
			{
				printf("Closing text file failed.\n");    //error checking
			}
			return 1;   
		}
	}

	if (fclose(textFile) == EOF)   // Closes file when reached the end. 
	{
		printf("Closing text file failed.\n"); 
	}


	return 0;
}




/*
* Fucntion Name: displayError()
* Parameters: A constant null-termianted string which will contain the required error message.
* Return Values: void
* Description: Takes a null-termintated string as a parameter and displays it as an error message for the requred situation. 
*/
void displayError(const char* error)
{
	fprintf(stderr, "Error: %s\n", error);
}