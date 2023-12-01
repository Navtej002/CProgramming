/*
* File Name: m4.cpp
* Project Name: Major Assignment 4
* Programmer's Name: Navtej Saini
* Date of First Revision: Nov. 27, 2023
* Description:
*/

#include <stdio.h>
#pragma warning(disable: 4996)

#define MAX_FILE_LENGTH 41

int main(void)
{

	char filename[MAX_FILE_LENGTH];

	FILE* teamsFile = fopen("teams.txt", "r");
	if (teamsFile == NULL)
	{
		printf("Error: Can't open teams.txt\n");
		return 1;
	}


	return 0;
}


int parseGames(const char* filename)
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








}