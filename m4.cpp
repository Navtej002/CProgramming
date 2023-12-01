/*
* File Name: m4.cpp
* Project Name: Major Assignment 4
* Programmer's Name: Navtej Saini
* Date of First Revision: Nov. 27, 2023
* Description:
*/

#include <stdio.h>
#include <string.h>


#pragma warning(disable: 4996)

#define MAX_FILE_LENGTH 41
#define MAX_LINE_LENGTH 41


int parseLine(char* wholeLine, char* teamName, int* teamScore, int* oppScore);
int processGames(const char* filename);



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
		

		int status = processGames(filename);

		if (status != NULL)
		{
			printf("Error processing %s\n", filename);
		}


	}


	return 0;
}


int processGames(const char* filename)
{
	int wins = 0;   //Counter for wins
	int losses = 0;  //Counter for losses
	int ties = 0;   //Counter for ties

	int teamScore = 0;
	int oppScore = 0;

	FILE* gameFile = fopen(filename, "r");
	if (gameFile == NULL)
	{
		printf("Error opening game file\n");
		return 1;
	}

	printf("Processing %s:\n", filename);


	char gameLine[MAX_LINE_LENGTH];

	char primaryTeam[MAX_FILE_LENGTH];
	char opposingTeam[MAX_FILE_LENGTH];


	strncpy(primaryTeam, filename, strlen(filename) - 4);
	primaryTeam[strlen(filename) - 4] = '\0';  // Remove ".txt" extension and ensure it null-terminates


	while (fgets(gameLine, sizeof(gameLine), gameFile) != NULL)
	{
		gameLine[strcspn(gameLine, "\n")] = 0;   //removes closing sequence "\n" if present

		int status = parseLine(gameLine, opposingTeam, &teamScore, &oppScore);

		if (status == 0)
		{
			printf("\t%s", primaryTeam);

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
				printf("tied with %s %d-%d\n", opposingTeam, teamScore, oppScore);
				ties++;
			}
		}
	}




    return 0;
}





int parseLine(char* wholeLine, char* teamName, int* teamScore, int* oppScore)
{
    char* comma = strchr(wholeLine, ',');
    if (comma == NULL)
    {
        printf("Error: Missing comma in line\n");
        return 1;
    }

    
    return 0;

}
