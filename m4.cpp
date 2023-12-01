/*
* File Name: m4.cpp
* Project Name: Major Assignment 4
* Programmer's Name: Navtej Saini
* Date of First Revision: Nov. 27, 2023
* Description:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable: 4996)  //for fopen() compiler warning

#define MAX_FILE_LENGTH 41 //Constant for file length 
#define MAX_LINE_LENGTH 41  // Constant for line length (gameLine)


int parseLine(char* wholeLine, char* teamName, int* teamScore, int* oppScore);  //Prototype for parseLine()
int processGames(const char* filename);   // Prototype for processGames()



int main(void)
{
	int status = 0;
	char filename[MAX_FILE_LENGTH];


	FILE* teamsFile = fopen("teams.txt", "r");
	if (teamsFile == NULL)
	{
		printf("Error: Can't open teams.txt\n");
		return 1;
	}


	while (fgets(filename, sizeof(filename), teamsFile) != NULL)
	{
		filename[strcspn(filename, "\n")] = 0;  //removes any "\n" characters if present 

		int status = processGames(filename);   // Calls processGames() function which handles all tasks for this program

		if (status != NULL)
		{
			printf("Error processing %s\n", filename);
		}

		printf("\n"); // Gives a blank line of space between processing gameFiles

	}

	if (fclose(teamsFile) != NULL)
	{
		printf("Closing file failed.\n");
	}


	return 0;
}


int processGames(const char* filename)
{
	double wins = 0;   //Counter for wins
	double losses = 0;  //Counter for losses
	double ties = 0;   //Counter for ties
	int teamScore = 0;
	int oppScore = 0;

	char primaryTeam[MAX_FILE_LENGTH];
	char opposingTeam[MAX_FILE_LENGTH];
	char gameLine[MAX_LINE_LENGTH];
	

	FILE* gameFile = fopen(filename, "r");
	if (gameFile == NULL)
	{
		printf("Error opening game file\n");
		return 1;
	}

	printf("Processing %s:\n", filename);

	strncpy(primaryTeam, filename, strlen(filename) - 4);
	primaryTeam[strlen(filename) - 4] = '\0';  // Removes ".txt" extension and ensure it null-terminates


	while (fgets(gameLine, sizeof(gameLine), gameFile) != NULL)
	{

		gameLine[strcspn(gameLine, "\n")] = 0;   //removes closing sequence "\n" if present

		int status = parseLine(gameLine, opposingTeam, &teamScore, &oppScore);

		if (status == 0)
		{
			printf("\t%s ", primaryTeam);

			if (teamScore > oppScore)
			{
				printf("beat %s %d-%d\n", opposingTeam, teamScore, oppScore);
				wins++;  //increments count of wins by 1
			}
			else if (teamScore < oppScore) {
				printf("lost to %s %d-%d\n", opposingTeam, teamScore, oppScore);
				losses++;  //increments count of losses by 1
			}
			else {
				printf("and %s tied at %d\n", opposingTeam, teamScore);
				ties++;
			}
		}
	}

	//Calculating Win Percentage and displaying
	if (wins + losses + ties > 0)
	{
		double winPercentage = (2.0 * wins + ties) / (2.0 * (wins + losses + ties));
		printf("Season result for %s: %.3lf (%.lf-%.lf-%.lf)\n", primaryTeam, winPercentage, wins, losses, ties);
	}
	else {
		printf("No valid games found for %s\n", filename); //displays error if wins, losses, and ties were not counted or 0.
	}

	if (fclose(gameFile) != NULL)
		{
			printf("Closing file failed.\n");
		}

    return 0;
}





int parseLine(char* wholeLine, char* teamName, int* teamScore, int* oppScore)
{
    char* comma = strchr(wholeLine, ',');     //strchr() searches gameLine for ","and assigns it to char pointer "comma"
    if (comma == NULL)
    {
        printf("Error: Missing comma in line\n");
        return 1;
    }

	
	strncpy(teamName, wholeLine, comma - wholeLine);  // Extracts teamName using comma position
	teamName[comma - wholeLine] = '\0';    // Ensures string is null-termianted. 

	
	char* dash = strchr(comma, '-');  //Finds "dash"-" using strchr() starting from comma position. Faster than searching wholeLine again.
	if (dash == NULL)
	{
		printf("Error: Missing dash in line\n");
		return 1;
	}

	
	*teamScore = atoi(comma + 1);  // Extract teamScore  using comma  position
	*oppScore = atoi(dash + 1);  // Extract oppScore  using dash  position

	return 0;
}


