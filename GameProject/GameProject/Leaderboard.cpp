#include "Leaderboard.h"
#include <fstream>
#include <iostream>
#include "MainFunctions.h"

using namespace std;
void getLeaderboard(int size, char** names, int* scores)
{

	ifstream inFile;
	switch (size)
	{
	case 4:
	{
		inFile.open("score4.txt");
		break;
	}
	case 5:
	{
		inFile.open("score5.txt");
		break;
	}
	case 6:
	{
		inFile.open("score6.txt");
		break;
	}
	case 7:
	{
		inFile.open("score7.txt");
		break;
	}
	case 8:
	{
		inFile.open("score8.txt");
		break;
	}
	case 9:
	{
		inFile.open("score9.txt");
		break;
	}
	case 10:
	{
		inFile.open("score10.txt");
		break;
	}
	}
	
	for(int v=0; v<5; v++)
	{
		char* name = new char[50] ();
		int a=0;
		inFile>>name>>a;
		names[v] = name;
		scores[v]=a;
		
	} 

	inFile.close();
}

void printLeaderboard(int size)
{
		int* scores = new int[6]();
		char** names = new char* [6];
		for (int i = 0; i < 6; i++)
		{
			names[i] = new char[50]();
		}

		getLeaderboard(size, names, scores);

		for (int i = 0; names[i][0]!='\0'; i++)
		{
			cout << i + 1 << ". ";
			for (int j = 0; names[i][j] != '\0'&&j<50; j++)
			{
				cout << names[i][j];
			}
			cout << " - " << scores[i]<<endl;
		}
		press();
}


int checkScore(char* nickname, int score, int size)
{
	int* scores = new int[6]();
	char** names = new char* [6];
	for (int i = 0; i < 6; i++)
	{
		names[i] = new char[50]();
	}

	getLeaderboard(size, names, scores);
	int i=-1;
	for (i = 0; i < 5; i++)
	{
		if (scores[i] < score)
		{
			for (int j = 4; j > i; j--)
			{
				names[j] = names[j - 1];
				scores[j] = scores[j - 1];
			}
			names[i] = nickname;
			scores[i] = score;
			break;
		}
	}
	
	ofstream outFile;
	
	switch (size)
	{
	case 4:
	{
		outFile.open("score4.txt");
		break;
	}
	case 5:
	{
		outFile.open("score5.txt");
		break;
	}
	case 6:
	{
		outFile.open("score6.txt");
		break;
	}
	case 7:
	{
		outFile.open("score7.txt");
		break;
	}
	case 8:
	{
		outFile.open("score8.txt");
		break;
	}
	case 9:
	{
		outFile.open("score9.txt");
		break;
	}
	case 10:
	{
		outFile.open("score10.txt");
		break;
	}
	}
	for (int k = 0; names[k][0] != '\0'; k++)
	{
		for (int j = 0; names[k][j] != '\0'; j++)
		{
			outFile << names[k][j];
		}
		outFile << "\t" << scores[k] << "\t";
	}

	outFile.close();
	return i+1;
}