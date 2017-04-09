#pragma once
#include <cmath>
#include <ctime>
#include <iostream>

void easyComputerAI(int displayGrid[3][3])
{
	bool computerPlayedTurn = false;
	int x, y;
	srand(time(0));
	
	for(int i = 0; i < 20; i++)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (displayGrid[x][y] == 0 && computerPlayedTurn == false)
		{
			displayGrid[x][y] = 2;
			std::cout << "COMPUTER PLACED O" << std::endl;
			computerPlayedTurn = true;
		}
	}
}

int** mediumComputerAI(int dispalyGrid[3][3])
{
	return 0;
}

int** hardComputerAI(int dispalyGrid[3][3])
{
	return 0;
}